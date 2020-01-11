# Archers

## Quick References


1. [Description](#project)
2. [Team Composition](#team)
2. [Running the Project](#run)
3. [Character Specification](#characters)
4. [Additional Features](#further)


<a name="project"></a>
## 1. Description 

In this project, we aimed to create our version of the Archers 2D game for desktop. Here, there is one player who shoots at several opponents. In the original game, there are several different opponents. In our version, we have chosen to implement 3 types: a running opponent that stabs the player, a standard opponent that shoots back, and a spear throwing opponent. In our version, it's in endless mode and is set to player v computer where the player controls the character using the mouse. 


<a name="team"></a>
## 2. Team Composition

Here are the members, their teams and roles:

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
  Tavdgiridze,
  Zhang

#### HUD:
  Hirsch
  
#### Game Design:
  Gomez,
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


<a name="run"></a>
## 3. Running the Project 

In our project, we have chosen to use the [SFML](https://www.sfml-dev.org/) library. To install it, do the following:

## Installing SFML

On the virtual machines (Linux) , write the following command in terminal:

    $> sudo apt-get install libsfml-dev

Enter the relevant passwords, and it should be installed. 

Consult the following for additional information on installing the library:

1. [macOS XCode](https://www.sfml-dev.org/tutorials/2.5/start-osx.php)

2. [Visual Studio](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)

3. [Code Blocks](https://www.sfml-dev.org/tutorials/2.5/start-cb.php)

## Building and Running the Project

First, clone the project into the local repository renaming it to 'Archers'. Next type in the following commands to run the project:

    $> cd Archers
    $> cd ArchersGame
    $> make clean
    $> make -j8 archer
    $> ./archer
    
This script should make the project and result in an SFML window with the game running.

The above script will equally make and build the project, creating the necessary executables, and download a pre-trained model.

<a name="characters"></a>

## 4. Character Specifications

In this section, we explain the features we currently have in the game with regard to the characters. First, here are the specifications for the main player:

### Players 

Players starts in a fixed position, bottom left, of the screen. It initialises the bow movement with the cursor and sets an angle for the arrow to be shot from. Force/speed of the arrow is decided by how far back you pull the cursor, i.e. the distance between the cursor and the sprite itself. The arrow is shot and follows projectile motion. Player dies if shot in the head once or shot anywhere else twice or if hit once by spear.

### Opponents

#### Type 1

Standard opponent. Appears in a randomised position, will continue shooting until dead. Will choose a random angle and shoot, again dies if shot in the head or shot anywhere else twice.


#### Type 2

Running opponent. Starts from one end of the screen and runs towards the player. Dies with same specifications however opponenet can't shoot. The weapon here is a knife, so it stabs the player if it reaches the player.

#### Type 3

Spear throwing opponent. Appears in a randomised position, will continue throwing spears until dead. If the spear hits player, player dies immediately. 

<a name="further"></a>
## 5. Additional Features
