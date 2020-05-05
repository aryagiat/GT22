***ENGG1340 GAME PROJECT - GROUP 22***

**Team Members:**

Giat, Arya Nagatama  3035662663;

Lioe, Andrew Tian    3035666633;


**Game Description:**
GT22 is an endless runner car racing game. The goal of the game is to overtake as many cars in front without crashing.

**Game Rule:**
There are three lanes in which the player will be on one of the lanes. There will be incoming traffic randomly appearing in one of the three lanes. Overtake the incoming cars by changing lanes. Each overtaken car results in an additional point. The run ends when the player crashes the car with the incoming traffic.
Players can collect different cars from the shop which can be acquired by collecting coins which randomly spawns on one of the three lanes. 



**Features / Functions:**

**1.  Generation of random game sets or events:**

    - Random placements of incoming traffic on one of the 3 lanes;
    - Random number of incoming traffic at once (1 or 2 cars only at once);
    - Random placement of a coin on one of the 3 lanes and on a random y-coordinate;
    - Random placement of turbo boost (i.e. extra points); (??)
    
**2.  Data structure for storing game status:**
    
    Structure (int x, int y):
    - x and y coordinates of the player and the incoming traffic;
    - if the x and y coordinates of the player and incoming traffic intercepts, the game ends;
    - if the y coordinates of the player is greater than the incoming traffic, the score is incremented;
    - if the x and y coordinates of the player and coin intercepts, the coin value is incremented;
    
    Doubly Circular Linked list:
    - To add options on a menu;
    - To navigate up and down the options on a menu;
    
**3.  Dynamic memory management:**

    - Vector class in STL to copy and paste each line of the startart screen graphics from a .txt file to the console screen.
    - Vector class in STL to copy and paste each line of the garageart screen graphics from a .txt file to the console screen.
    - Vector class in STL to copy and paste each line of the instructions screen graphics from a .txt file to the console screen.
    - Vector class in STL to copy and paste each line of the difficulty screen graphics from a .txt file to the console screen.
    - Doubly Circular Linked lists to let revolving occur when reaching the top-most or bottom-most option in any menu screen.
    
**4.  File input / output:**

    - Highscore (line 1) and coin total (line 2) saving file in which new highscores and coin in/decrements are outputted to. It is also an input file to show the highscore and coin total on the console screen.
    - Start screen graphics art design, instruction screen design, garage screen design, difficulty screen design.
    - Car file to define different cars' specifications (i.e. appearance) and if it is unlocked or not.
    - startart.txt        --> The graphics design of the start menu
    - stat.txt            --> Storing the highscore and coins acquired
    - availableCars.txt   --> Storing the cars owned
    - garageArt.txt       --> The graphics design of the garage menu
    - difficultyArt.txt   --> The graphics design of the difficulty menu
    - instructions.txt    --> The graphics design of the instructions menu

**5.  Program codes in multiple modules:**

    - Start / home screen program (start.cpp).
      - Outputing start graphic design
      - Start button
      - Selecting car button
      - Instruction button
      - Reset game data button
      - Exit button
      - High score and coins displayed
      
    - Start header (start.h)
      - A header to define the main() function in start.cpp
      
    - Garage screen header (garage.h).
      - Outputing the garage graphic design
      - Showing cars which are locked or unlocked
      - Purchasing cars
      - Selecting an owned car to race with
      - Returns the chosen car by the user to start.cpp
      
    - Difficulty screen header (difficulty.h)
      - Outputing the difficulty screen graphic design
      - Showing the different difficulties
      - Selecting a difficulty of the race
      - Returns the speed of the car as the difficulty.
     
    - Game screen header (console.h).
      - Generating incoming cars with random position on 1 or 2 of 3 lanes
      - Generating coins randomly on a random coordinate
      - Current position of player's car and key presses to move the car
      - Score counter
      - Coin counter
      - Player movement and position control
      - Checking for collisions between player and coin or incoming cars
      
    - Key press detection program (keylog.cpp).
      - Our version of a program inspired by niko from https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
      - Making a new terminal input/output settings to get user input
      - Read a character from a keyboard input without echoing the character to the console
      - Changing back to old terminal input/output settings to prevent errors
      - Returns a character pressed
      
    - Key press detection header (keylog.h).
      - To define the keylog() function in keylog.cpp which returns a character
    
    - Doubly circular linked list creator program (linkedlist.cpp).
      - Making a linked list which is doubly circular
      - Stores an integer value on each node, stores the next node, and stores the previous node
     
    - Doubly circular linked list creator header (linkedlist.h).
      - To define the void ListBuild() function in linkedlist.cpp which has a struct Node and integer parameter
