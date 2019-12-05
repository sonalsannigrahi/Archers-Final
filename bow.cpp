#include bow.hpp


Player::Players(){
	srand (time(NULL));
	sf::Texture* texture = new sf::Texture();
	texture -> loadFromFile("charac_arm.png")
	sf::Sprite* sprite = new sf::Sprite(*texture)
	sf::Texture* texturem = new sf::Texture();
	texturem -> loadFromFile("hand_p.png")
	sf::Sprite* spritem = new sf::Sprite(*texturem)
}

void Player::setWindow(sf::RenderWindow* gameWindow){
	window = gameWindow;
}

void Player::setsize(int width, int height ){
	playerwidth = width;
	playerheight = height;
}

void Player::updateFrame(double time){
	// need to test implementation
    sf::Vector2i mouse;
    float angle;
    sf::Vector2f playerPosition;
    double a, b;	

    spritem.setOrigin(sprite.getOrigin().x,sprite.getOrigin().y);
    playerPosition = spritem.setPosition(sprite.getPosition().x,sprite.getPosition().y);
    spritem.setRotation(0);
    sf::Event Event;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    	a = mouse.x - playerPosition.x;
        b = mouse.y - playerPosition.y;
        mouse = sf::Mouse::getPosition(window);
        angle = -atan2( a , b) * 180 / 3.14;
        spritem.setRotation(angle);
}
