# Archers

This is a 2d archer game, where the user controls an immobile player character which can shoot arrows with varying power and angle. The aim is to add enemies that will shoot back at the player.

## Team Composition:

  Saba Tavdgiridze (Team Leader) 
  
  Diego Gomez
  
  Alexandre Hirsch
  
  Nícolas Lopes
  
  André Renom
  
  Alice Aubert (Git Master)
  
  Minh Tuan Nguyen (Project Manager)
  
  Sunho Hwang
  
  Hoang Anh Ngo
  
  Jiwon Park
  
  Sonal Sanigrahi
  
  Tarcisio Soares Teixeira Nieto
  
  Maëlys Solal
  
  Chris Zhang
  
  
## Teams:
#### Physics Engine:
  Renom,
  Lopes,
  Zhang,
  Tavdgiridze

#### HUD:
  Hirsch
  
#### Game Design:
  Gomes,
  Park,
  Hwang,
  Nguyen

#### Character:
  Solal,
  Aubert,
  Sannigrahi

#### UI & Backend:
  Soares,
  Ngo

## Installing Relevant Libraries
Our game uses SFML as its graphics library. The following is a link to the different tutorials on how to install it across all supported operating systems https://www.sfml-dev.org/tutorials/2.5/#getting-started. 

Here we provide a tutorial for how to install it on Linux.

First, one must open the terminal and input the following command: sudo apt-get install libsfml-dev. After inputing the relevant passwords, SFML should be installed. 

Now one must compile the .cpp files and make the main method an executable sfml application. To do this, we first compile all relevant files (including the one contaning the main method) using the normal g++ compiler. Once that is complete, we make the main method executable using the following command: g++ (mainMethodFileName).o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

Now the program is an executable game which runs after typing the following command: ./sfml-app
