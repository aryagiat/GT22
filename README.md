***ENGG1340 GAME PROJECT - GROUP 22***

**Team Members:**

Giat, Arya Nagatama  3035662663;
Lioe, Andrew Tian    3035666633;


**Game Description:**
GT22 is an endless runner car racing game. The goal of the game is to overtake as many cars in front without crashing.

**Game Rule:**
There are three lanes in which the player will be on one of the lanes. There will be incoming traffic randomly appearing in one of the three lanes. Overtake the incoming cars by dodging the traffic. Each car dodged results in an additional point. The run ends when the player crashes the car with the incoming traffic.
Players can collect different cars from the shop which can be acquired by collecting coins which randomly spawns on one of the three lanes. 



**Features / Functions:**

**1.  Generation of random game sets or events:**
    - Random placements of incoming traffic on one of the 3 lanes.
    - Random number of incoming traffic at once (1 or 2 cars at once).
    - Random placements of a coin on one of the 3 lanes.
    
**2.  Data structure for storing game status:**
    -  x and y coordinates of the player and the incoming traffic
    - if the x and y coordinates of the player and incoming traffic intercepts, the game ends
    
**3.  Dynamic memory management:**
    - 
    
**4.  File input / output:**
    - Highscore saving file in which new highscores are outputted to. It is also an input file to show the high score on the console screen.
    - Coin file in which the number of coins acquired from a run are added to the file. It is also an input file to show the amount of coins that the player have.
    

**5.  Program code in multiple files:**
    - Start / home screen program.
      - Start button
      - Selecting car button
      - Instruction button
      - Reset game data button
      - Exit button
      
    - Pause screen program.
      - Resume button
      - Return to home button
      
    - Game screen program.
      - Generating incoming cars with random position (1 of 3 lanes)
      - Generating coins
      - Current position of player's car and key presses to move the car
      - Point system
      
    - Player's car program.
      - Hitbox of the car
  
    - Incomming traffic car program.
      - Hitbox of the incoming traffic cars
