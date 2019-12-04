#include bow.hpp


Player::Players(){
	srand (time(NULL));

	for (int i=0; i< playerconstant.filenamelen; i++){
		sf::Texture* texture = new sf::Texture();
		texture -> loadFromFile("Character/Assets/" + playerconstant.filename[i]);
		sf::Sprite* sprite = new sf::Sprite(*texture);
		texturem -> loadFromFile("Character/Assets/" + playerconstant.filename[i]);
		sf::Sprite* spritem = new sf::Sprite(*texturem)
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
    sf::Vector2i mouse;
    float angle;
    sf::Vector2f playerPosition;
    double a, b;	

    spritem.setOrigin(charactersprite.getOrigin().x,charactersprite.getOrigin().y);
    spriteposition = spritem.setPosition(charactersprite.getPosition().x,charactersprite.getPosition().y);
    spritem.setRotation(0);
    sf::Event Event;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    	a = mouse.x - spriteposition.x;
        b = mouse.y - spriteposition.y;
        mouse = sf::Mouse::getPosition(window);
        angle = -atan2( a , b) * 180 / 3.14;
        spritem.setRotation(angle);
}
