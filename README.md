# Archers

## Quick References


1. [Description](#project)
2. [Team Composition](#team)
2. [Running the Project](#run)
3. [Character Specification](#characters)
4. [Additional Features](#further)


<a name="project"></a>
## 1. Description 

In this project, we aimed to create our version of the Archers 2D game for desktop. Here, there is one player who shoots at several opponents. In our version, we have chosen to implement 3 types: a running opponent that stabs the player, a standard opponent that shoots back, and a spear throwing opponent. In our version, it's in endless mode and is set to player v computer where the player controls the character using the mouse. 


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

The above script will make and build the project, creating the necessary executables, and compiling all the dependencies.

Once you have the excutable game window, choose your username and press 'Enter' to begin the game. During the game, press 'esc' to pause the game. Here, the settings page will pop up. Once you unpause the game, you can resume playing. 

<a name="characters"></a>

## 4. Character Specifications

In this section, we explain the features we currently have in the game with regard to the characters and how you can control the movement of the player. First, here are the specifications for the main player:

### Players 

The player is set at a fixed position, towards the bottom left of the screen. This player can set an angle for the bow based on the movement of the mouse, and then add aditional force with how far back you pull the mouse. Then, an arrow gets released which follows projectile motion. The player also has a healthbar on the screen which changes at when health is at 100% and at 50%. The player will be defeated in the game if it has been hit twice by the running opponenet, once in the head by a spear or an arrow, or twice in the body by a spear or an arrow. In this game, the objective is to get the highest kill count or score.

### Opponents

#### Type 1

This is the standard opponent which behaves exactly like the main player. However, as an opponent this character chooses a randomised angle each time instead of being controlled by the cursor movements. Like the player, this opponenet has a healthbar and will die if it shot once in the head or twice in the body. 


#### Type 2

The second type of opponent is a running opponent which runs across the screen and aims to stab the player. It dies with the same specifications as above, but this opponent can't shoot at the player. 

#### Type 3

The last type of opponent is a spear throwing opponent which throws spears at randomised power levels. The spear opponents spawn rate is set quite high so as to ensure a progressive difficulty. Further, the speared opponenet also has a decay rate which allows the spawn rate to decrease with time, making it appear more and more often in the game as the player continues. 

<a name="further"></a>
## 5. Additional Features

#### Start and End Screen

In the start screen, the user can choose a player name which will be used to display the best scores. After choosing a name, we have a main menu where you can choose to start the game, view best scores, train on the tutorial, or quit the game. 

In the end screen, the user can see their current score and then choose to reither replay the game or exit and go back to the main menu. 

#### Tutorial

In order to make the game more user friendly, we have included a tutorial for the game. In the tutorial, the player gets to practice shooting at 5 randomised targets in order to get used to the game structure. The tutorial also points out features such as the healthbar.

#### Settings

The settings page appears either if the user clicks on the settings button on the top right corner of the screen or if the game has been paused (esc button). In the settings, the user can choose the size of the game, control the volume (game volume and volume of rain, birds, fireworks, etc.), choose different backgrounds for the game, choose if the birds, fireworks, balloons, and rain appears or not. By default, we have set the birds to true. The settings page also makes use of encryption to remember the settings that the user had chosen before. So if I choose a certain background the first time, the second time I run the game the background is remembered. 

#### Best Scores

Each user gets attributed a certain score and in the home page, the user can choose to view a leadership board showing the highest scores the user that attained in all previous tries. In order to do this, our team worked on encrypting a text so that the user can't change the scores in the text file.

#### Retro Mode

If the user chooses retro mode, the user gets directed to an arcade version of the game. In this version, we have the following features:

#### TO COMPLETE RETRO MODE
