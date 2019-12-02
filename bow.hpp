#include player.hpp


Player::Players(){
	srand (time(NULL));

	for (int i=0; i< playerconstant.filenamelen; i++){
		sf::Texture* texture = new sf::Texture();
		texture -> loadFromFile("Character/Assets/" + playerconstant.filename[i]);
		sf::Sprite* sprite = new sf::Sprite(*texture);
		charactersprite.push_back(*sprite);

	}
}

void Player::setWindow(sf::RenderWindow* gameWindow){
	window = gameWindow;
}

void Player::setsize(int width, int height ){
	playerwidth = width;
	playerheight = height;

}

void Player::updateFrame(double time){
	// need to finish implementation
}



