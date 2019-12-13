# Record of Weekly Logs
This is a place to centralise each person's weekly log, so that it can then be sent at the end of each week.

The weeks will be recorded from saturday to friday, since the weekly logs are submitted on friday evening.

## Week 1 (16th Nov - 22nd Nov)

Andre Renom & Nicolas Lopes - This week we began planning the physics engine, and researched different ways of implementing it.
we settled that we needed to create a class of foces that would make our engine more adaptable and easier to complexify.
Our initial goal, which we will begin implementing next week, is to add gravitational and air resistance forces.

Alexandre Hirsch - This week, I began researching the menu class of our SFML game. In the following weeks, I will work on implementing it and other aspects of the HUD.

Sunho Hwang - This week we began planning on the general game design and what it would require. Our first goal would be to figure out the game map, the animations required, etc.

Minh Tuan Nguyen - Divided the team into smaller subteams for specific tasks, created a basic game class. Next week, we will set up basic classes (ie. background, water, ground).

Hoang Anh Ngo - This week, I began to research on how to create splash screen/main menu screen and Game over screen. Start implementing the first lines of code for the Splash screen state. Next week, creating functions/buttons for the screens and start to think of the graphics.

Tarcisio Teixeira - This week, after setting everything up, I began planning the encryption of data and the structures to save them. Next week I plan to create an encryption class.

Sonal Sannigrahi - I have implemented a version of controlling the angle of the bow movement using the cursor. Still under testing and debugging. Next week, I will look into more functionalities of the characters involved.

Maelys Solal - This week I focused on setting up the VM and getting familiar with SFML. I began thinking about the Character, Opponent and Weapon classes. Next week, I will start implementing them and I will also continue learning about SFML. 

Alice Aubert - This week I helped set up the Trello and get everyone on the github repository. With the character player team we outlined the basic elements we wanted to include in the player and arrow class. I then has a existential break down trying and failing to install both the virtual machine and Xcode. Next week I will try to get one of them to work. 

Zhang Xingjian & Saba Tavdgiridze - We analyzed how to detect intersection for objects and resolve them. Next week, we will write the part of the code which is responsible for that part of the game.

Jiwon Park - This week I looked over SFML libraries how to draw 2D figures on window to start working on implementing basic classes such as game map.

## Week 2 (23rd Nov - 29th Nov)

Andre Renom - Met with Saba, Nicolas and Chris to discuss Physics engine, implementation was started with a vector and pointmass framework of forces. Vector operations were created to help with later development. Air resisitance as implemented as a force on a pointmass, and started BlackHoles were added as a subclass of Pointmasses.

Xingjian Zhang & Saba Tavdgiridze - Met with Physics Engine group members for discussion last Sunday. Began implementation of vector and pointmass frameworks and worked on solving collision.Implemented a demo in a subbranch with very basic collisions and simple gravity. Next week, we will continue improving the collison detector and physics necassary for resolving them(We will use general convex polygons instead of circles for each object.)

Sonal Sannigrahi- Looking into sprite animation vs vector graphics through drawables. Implemented a click and drag function for the bow/arrow. Will be implementing character movements next.

Jiwon Park -  Began the mplemention of the ground where characters stand on and looking for sprite that will be used in our black hole.

Sunho Hwang - Began and finished the implementation of the bird classs with animations. Started on another balloon class. Some animations still require polishing.

Diego Gomez - This week I searched for animations for water and fireworks and implemented them in their corresponding classes. 

Tarcisio Teixeira - I began and almost finished the implementation of the Encryption class needing just some more tests and merge with the rest of the code. Some part of it will be done just when the table of constants is ready. Next week I will start working on UI-UX part.

Minh Tuan Nguyen - Set up the game class so it can work together with other classes; Grouped and tested game, background, water and birds classes together; Optimized the game performance by changing ways variables are initialized. Next week I will put all the other classes (rain, lightning, fireworks,...) together and begin researching on audio and sound.

Alexandre Hirsch - Began the outline of the main menu: Play, Settings, Quit. Next week will be focused on discussing what aspects of the game can be altered in the settings, although this will be subject to change if we decide to remove or add functionalities.

Maëlys Solal - This week I started the implementation of the character and opponents class. I also changed the structure we had initially thought of in order to make it more useable. Next week I will start creating different types of opponents.

Alice Aubert - This week I started to implement the arrow class keeping in mind how the physics engine would affect the graphics. I also worked to implement both the arrow and Character classes as subclasses of the Drawables class of SFML. Next week I plan to continue this to make sure that both the Characters and arrows interact smoothly ie the character can shoot the arrow correctly using the click and drag function. 

Nicolas Lopes - Met with Saba, Andre and Chris to discuss Physics engine. Corrected some small mistakes in previous code, changed the class of ConstantGravity, added cossine, sine and vector product as well as discussed about and started the BlackHole class with Andre. Discussed about implementation of air resistance.

## Week 3 (30th Nov - 6th Dec)

Sonal Sannigrahi - Designed all the character (opponent and player) sprites. Integrated code to rotate bow with the character sprites and game window. For now, the bow with the arm rotates with the rest of the sprite fixed. Code is functional right now. For next week, I will be working on resizing the sprites to match the game window, placing the character on a ground, and finally fixing the arm in the right position.

Sunho Hwang - Finished the implementation of the falling balloon class. We are now able to set up the balloon class so that it will fall randomly throughout the game. Moved onto implementing sounds for the animated sprites. So far, I have found various samples that can be used. Still needs to address how to implement them into the game itself.

Diego Gomez - This week I finished the implementation of the fireworks class into the game, that is we are now capable of shooting fireworks at will in the game. I also started to search and implement sound for other objects, but I have come across a compatibility error that still needs to be addressed.

Alice Aubert - This week I looked to implement arrows as sprite and finding a suitable image. Next week, I will implement the mathematical equations to make them into projectiles.

Minh Tuan Nguyen - Implemented rain and lightning and integrated them into the game, helped integrate other classes. Next week, I will try to implement sound system and add the encription class to encript game constants.

Tarcisio Teixeira - Finished tests on Encryption and start working on UI-UX. On UI-UX, after having divided and made a scratch of the classes that will be needed I start working on the implementation of start screen.

Saba Tavdgiridze & Xingjian Zhang - Finished well-functioning collision resolution part of the game. Started thinking about how to integrate it into the game.

Nícolas Lopes - Implemented the BlackHole class and started the object class. Solved the collision problem in 2 dimensions, making it more realistic and simpler to implement. Solved the rotation of rigid bodies problem in accordance with real physics, making a link with the collisions code, allowing us to implement it in the next week.

Maëlys Solal - This week I continued thinking about opponents but mostly focused on the healthbar. The healthbar is now no longer just a player's attribute but now a full object with its own sprite which I am implementing. Next week I hope to finish implementing the healthbar and continue working on opponents.

André Renom - Discussed with the character team how their classes would interact with the phyics engine, and the extent to which theirs would be subclasses of the abstract objects defined in the physcics engine. Started thinking about the implementation of wind, which will be continued next week.

Alexandre Hirsch - Discussed what we will be able to change in the settings of the game. We will be able to change the difficulty setting, the presence of rain, lightning, birds, balloons, as well as their spawn rate, and sound settings. I have also been working on a rough first version of our main menu. Next week I will be working on the menu and begin programming the settings and linking it to other teammembers' work.

Hoang Anh Ngo - Re-implementing the whole structure of UI/UX, starting with the implementation of buttons and splash screen/game over screen

Jiwon Park - Finish the implementation of ground and started the implementation of blackhole. I looked over the phycis engine to see how it will be implemented to the game. 

## Week 4 (7th Dec - 13th Dec)

Andre Renom - Finalised discussions on completion of physics engine and how to treat game objects. Now working on coordinating the implementation of the physics engine with the charcter development team. Documented classes and processes. Tested collisions and a few limit cases of engine.

Sunho Hwang - This week i worked on the implementation of sounds of birds and also the background music. There were various issues when choosing appropriate sound samples as they had to match with the general atmosphere of the game. I also helped to implement functions which would eventually enable us to control the volume, change the background, etc. 

Diego Gomez - This week I added sound and functions that allow us to control  the level of said sound for the fireworks, lightning and rain classes. The implementation was not as easy as I thought it would be as I had some compatibility errors at first, and it was not enough to just play the sound when in the constructor function. For example for the lightning I had to add a delay to make more realistic, and I had to loop the sound for the rain. Next week I will start creating a new level ( training level ).

Tarcisio Teixeira - This week I worked on encryption class. I start implementing a method to be able to write all constant in a txt file this way being able to save information for the next time one plays. I also kept working on the start screen. I’m planning to finish encryption next week and try to merge with the rest of the code.

Xingjian Zhang - Tested collisions and black holes and worked on finalizing the physics engine. Next week, hopefully physics engine will be fully implemented and I will join Diego in creating a training/practice level in the game.
