# Character Specifications 

If trying to run, download the ArchersGame folder from UI/UX-Tarcisio-Hoang Anh branch and then replace Character, Arrow, Opponent, Game folders with the ones from here. Couldn't merge.  

## Players 

Players starts in a fixed position, bottom left, of the screen. It initialises the bow movement with the cursor and sets an angle for the arrow to be shot from. Force/speed of the arrow is decided by how far back you pull the cursor, i.e. the distance between the cursor and the sprite itself. The arrow is shot and follows projectile motion. Player dies if shot in the head once or shot anywhere else twice or if hit once by spear.

## Opponents

### Type 1

Standard opponent. Appears in a randomised position, will continue shooting until dead. Will choose a random angle and shoot, again dies if shot in the head or shot anywhere else twice.


### Type 2

Running opponent. Starts from one end of the screen and runs towards the player. Dies with same specifications however opponenet can't shoot. The weapon here is a knife, so it stabs the player if it reaches the player.

### Type 3

Spear throwing opponent. Appears in a randomised position, will continue throwing spears until dead. If the spear hits player, player dies immediately. 
