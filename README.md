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
    
    2D Array to be implemented:
    - x and y coordinates of the player and the incoming traffic;
    - if the x and y coordinates of the player and incoming traffic intercepts, the game ends;
    - if the y coordinates of the player is greater than the incoming traffic, the score is incremented;
    - if the x and y coordinates of the player and coin intercepts, the coin value is incremented;
    
**3.  Dynamic memory management:**

    - //Dynamic array to keep the highscore and coins obtained and to output those to the screen map\\. (??)
    - Vector STL to copy and paste the start screen graphics from a txt file to the console screen.
    - Linked lists to let revolving occur when reaching the top-most or bottom-most option in any menu screen.
    
**4.  File input / output:**

    - Highscore (line 1) and coin total (line 2) saving file in which new highscores and coin in/decrements are outputted to. It is also an input file to show the highscore and coin total on the console screen.
    - Start screen graphics art design, instruction screen design, garage screen design.
    - Car file to define different cars' specifications (i.e. health and appearance) and if it is unlocked or not.

**5.  Program codes in multiple modules:**

    - Start / home screen program (start.cpp).
      - Start button
      - Selecting car button
      - Instruction button
      - Reset game data button
      - Exit button
      - High score and coins displayed
      
    - Pause screen program.
      - Resume button
      - Return to home button
     
    - Game screen program (console.h).
      - Generating incoming cars with random position on 1 or 2 of 3 lanes
      - Generating coins randomly on a random coordinate
      - Generating boost
      - Current position of player's car and key presses to move the car
      - Point counter
      - Coin counter
      - Player movement and position control
      - Checking for collisions between player and coin or incoming cars
