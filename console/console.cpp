#include <iostream>
#include <cstdlib>  //rand, srand
#include <ctime>    //time
#include <unistd.h> //usleep
#include "../keylog.h" //keylog
#include <pthread.h> //pthread

using namespace std;

// The character map of the track
char map[19][20] = {
	"###################",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |     |     #",
	"#     |  A  |     #",
	"###################"};

// Coordinate system for the incoming vehicles and the user's car
struct Coordinate{
	int x; // the column
	int y; // the row
};


// Public variables:
Coordinate car1; // coordinates for incoming car 1
Coordinate car2; // coordinates for incoming car 2
Coordinate user; // coordinates for the user's car
Coordinate coin; // coordinates for the coin
bool game_running = true; // to check whether game is still running
int score = 0; // starting score on a single run
int coins = 0;
int delay = 100000; // animation delay which controls the speed of the incoming vehicles
char CARSHAPE = 'A';


// Function to print the map to the screen.
void PrintMap(){
	for (int i = 0; i < 19; i++){
		cout << map[i] << endl;
	}
}

// Function to spawn coins randomly.
void SpawnCoin(){
	int bias = rand()%100 + 1; // If bias < 60, it will spawn a coin. Otherwise it wont spawn a coin.
	if (bias <= 60){
		coin.x = (rand()%3 + 1) * 6 - 3; // Spawns coin on a random lane.
		coin.y = rand()%6+1; // Spawns coin in a random y coordinate from 1-6.
	}
	else{
		coin.x = 99; // Coin will not spawn if the x coordinate is 99.
	}
}

// Void function that spawns a single incoming traffic randomly on a lane.
void SingleTraffic(){
	bool in_screen = true; // Checking whether the incoming car is still in the screen.
	int lane; // lane is the lane number (between 1 - 3).
	int time_delay; // time_delay is the delay between screen refresh in microseconds. It also tells the speed of the car. The shorter the delay, the faster the car.

	lane = rand()%3 + 1; // Selecting a random lane to spawn the incoming car.
	car1.x = lane * 6 - 3; // Converting lane 1/2/3 into the x axis of the map 3,9,15 respectively.
	car1.y = 0; // car spawns at y axis 0.
	coin.y = 0; // Initializing coin y coordinate as 0.

	SpawnCoin(); // Randomly decides whether coin will be spawned or not.

	// Loop while the incoming car is still in the screen.
	while (in_screen){
		system("clear"); // clear console screen
		car1.y++; // move the incoming car down the screen.
		// Check whether coin is spawned. If coin.x == 99, coin is not spawned. If coin is spawned, move coin down the screen
		if (coin.x != 99 && coin.y < 15){
			coin.y++;
		}
		else{
			coin.x = 99; // Despawning coin once it leaves the screen.
		}

		// If the car is still within the screen:
		if (car1.y < 16){
			map[car1.y][car1.x] = '^'; // Spawning the car at its respective x and y coordinates.
			if (coin.x != 99 && coin.y < 15){
					map[coin.y][coin.x] = '.'; // Spawning the coin at its respective x and y coordinates.
			}
			PrintMap(); // printing the map.
			cout << "Score: " << score << endl;
			cout << "Coins: " << coins << endl;
			cout << "car1.x: " << car1.x << endl;
			cout << "car1.y: " << car1.y << endl;
			cout << "user.x: " << user.x << endl;
			cout << "user.y: " << user.y << endl;
			map[car1.y][car1.x] = ' '; // Remove the car trail.
			if (coin.x != 99 && coin.y < 15){
					map[coin.y][coin.x] = ' '; // Removing coin trail.
			}
		}
		// If the car has left the screen.
		else{
			PrintMap(); // Print map.
			score++; // Successfuly overtaken the incoming car, thus increment the point.
			in_screen = false; // car has left the screen.
		}

		// Checking for collision between the incoming car and the user.
		if (user.x == car1.x && user.y == car1.y){
			game_running = false; // ends the game
			system("clear");
		}

		// Checking for collision between coin and the user.
		if (user.x == coin.x && user.y == coin.y){
			coins++; // Successfuly gained a coin.
			map[user.y][user.x] = CARSHAPE;
		}

		// Setting the speed of the incoming vehicle. As the score increase, the speed will be faster.
		time_delay = delay - 1000 * score;
		if (time_delay <= 30000){
			// To make sure that the time delay is a positive integer.
			time_delay = 30000;
		}
		usleep(time_delay); // Screen refresh delay in microseconds.
	}
}


// Void function that spawns a double incoming traffic randomly on 2 different lanes.
void DoubleTraffic(){
	bool in_screen = true; // Checking whether the incoming cars are still in the screen.
	int lane1, lane2; // lane1 and lane2 are the lane numbers of car1 and car 2 respectively (between 1-3).
	int time_delay; // time_delay is the delay between screen refresh in microseconds. It also tells the speed of the car. The shorter the delay, the faster the car.

	lane1 = rand() % 3 + 1; // Selecting a random lane to spawn car1.
	lane2 = rand() % 3 + 1; // Selecting a different random lane to spawn car2.
	while (lane2 == lane1){
		lane2 = rand() % 3 + 1;
	}
	car1.x = lane1 * 6 - 3; // Convertaing lane 1/2/3 into the x axis of the map 3/9/15.
	car2.x = lane2 * 6 - 3; // Convertaing lane 1/2/3 into the x axis of the map 3/9/15.
	car1.y = 0; // both car1 and car2 will have the same y axis represented by car1.y. they both spawn at y axis 0.

	// Loop while the incoming cars are still in the screen.
	while (in_screen){
		system("clear"); // Clear console screen.
		car1.y++; // Move the incoming cars down the screen.

		// If the car is still within the screen:
		if (car1.y < 16){
			map[car1.y][car1.x] = '^'; // Spawning car1 at its coordinates
			map[car1.y][car2.x] = '^'; // Spawning car2 at its coordinates
			PrintMap(); // printing the map.
			cout << "Score: " << score << endl;
			cout << "Coins: " << coins << endl;
			cout << "car1.x: " << car1.x << "  car2.x: " << car2.x << endl;
			cout << "car.y: " << car1.y << endl;
			cout << "user.x: " << user.x << endl;
			cout << "user.y: " << user.y << endl;
			map[car1.y][car1.x] = ' '; // Remove trail of car1.
			map[car1.y][car2.x] = ' '; // Remove trail of car2.
		}
		// If both cars have left the screen.
		else{
			PrintMap(); // Print map.
			score += 2; // Successfuly overtaken the incoming cars, thus increment the score by 2.
			in_screen = false; // cars have left the screen.
		}

		// Checking for collision between the incoming cars and the user.
		if ((user.x == car1.x && user.y == car1.y) || (user.x == car2.x && user.y == car1.y)){
			game_running = false; // ends the game
		}

		// Setting the speed of the incoming vehicle. As the score increase, the speed will be faster.
		time_delay = delay - 1000 * score;
		if (time_delay <= 30000){
			// To make sure that the time delay is still playable and a positive integer.
			time_delay = 30000;
		}
		usleep(time_delay); // Screen regresh delay in microseconds.
	}
}

// Void pointer function that spawns a random number of Incoming car(s). Can generate 1 or 2 cars randomly. The input of the function is a void pointer that has no value.
void * Traffic(void * none){
	int number_of_cars; // The number of cars to be generated

	// Keep generating while game is still running
	while (game_running){
		number_of_cars = rand()%2 + 1; // Randomly choose whether the game spawns 1 or 2 cars.

		// Make sure that only 1 car is generated when the score is still below 5.
		if (score < 5){
			number_of_cars = 1;
		}

		// Generate a single incoming car.
		if (number_of_cars == 1){
			SingleTraffic();
		}

		// Generate two incoming cars.
		else if (number_of_cars == 2){
			DoubleTraffic();
		}
	}
}

// Void function to control player movements.
void PlayerMovement(){
  // Player originally spawns at these coordinates
	user.x = 9;
	user.y = 15;

	char key; // The key that the player press on the keyboard.
	// Keep getting user input until game stops running.
	while (game_running){
		system("clear"); // Clear Screen.
		PrintMap(); // Print map.
		key = keylog(); // Getting key press.

		// if 'a' is pressed, move left if the player is not on the most left lane
		if (key == 'a' && user.x != 3){
			map[user.y][user.x] = ' ';
			user.x -= 6;
		}

		// if 'd' is pressed, move right if the player is not on the most right lane
		if (key == 'd' && user.x != 15){
			map[user.y][user.x] = ' ';
			user.x += 6;
		}

		// exit game if user press q.
		if (key == 'q'){
			game_running = false;
		}

		// Update the coordinates of the car.
		map[user.y][user.x] = CARSHAPE; // the shape of the car is 'A'.
	}
}


// Main function.
int consoleMain(){ //cannot have function called main() when linking
	srand(time(NULL)); // Generating random seed

	// Using multithreading to run 2 functions at the same time.
	pthread_t traffic_thread; // Initializing a thread called traffic_thread.
	int t1 = pthread_create(&traffic_thread, NULL, Traffic, NULL); // Running the Traffic function on the traffic_thread.

	PlayerMovement(); // Running the PlayerMovement function simmultaneosly with the traffic_thread.

	pthread_join(traffic_thread, NULL); // Make sure the threads join at the end.

	// Once game_running is false
	cout << "you crashed!" << endl;
	cout << "Your score is: " << score - 1 << endl;
	cout << "Your coin is: " << coins << endl;
	return 0;
}

int main(){
    consoleMain();
}
