#include "bow.hpp"

Player::Player(){
    //creating three textures for the arm, body, arrow
	sf::Texture* body = new sf::Texture();
	body -> loadFromFile("Character/charac_arm.png");
	spriteb -> setTexture(*body);
	sf::Texture* hand = new sf::Texture();
	hand -> loadFromFile("Character/hand_p.png");
	spriteh -> setTexture(*hand);
    sf::Texture* arrow = new sf::Texture();
    arrow -> loadFromFile("Character/arrow.png");
    spritea -> setTexture(*arrow);
}


void Player::setWindow(sf::RenderWindow* gameWindow){
    //set window to game window
	window = gameWindow;
}

void Player::setSize(int width, int height ){
    winWidth = width;
	winHeight = height;
}

void Player::updateFrame(double time){
	// for now: rotates bow with limited positive angle, drag below to rotate the bow upward, arm position is correct, sizing is also correct, position fixed. 

    //counter += time;

    float angle;
    sf::Vector2f playerPosition;
    sf::Vector2i windowPosition;
    sf::Vector2i mousePosition;
    sf::FloatRect handSize;
    sf::FloatRect bodySize;
    //float arrowSpeed;
    //sf::Vector2i arrowComponents;
    double a, b;	

    spriteh -> setScale(0.25f,0.25f); 
    //spritea -> setScale(0.3f, 0.3f);
    spriteb -> setScale(0.25f, 0.25f);

    handSize = spriteh -> getGlobalBounds();
    bodySize = spriteb -> getGlobalBounds();

    spriteh -> setOrigin(float(handSize.width)/2,float(handSize.height)/2);

    spriteb -> setPosition(float(winWidth)/25, float(winHeight)/1.8);      

    spriteh -> setPosition(spriteb -> getPosition().x + float(bodySize.width)/2.5 ,spriteb -> getPosition().y + float(bodySize.height)/4);
    
    playerPosition = spriteh -> getPosition();
    /*
    arrowSpeed = 2;
    spritea -> setPosition(spriteh -> getPosition().x, spriteh -> getPosition().y);
    */

    spriteh -> setRotation(0);


    mousePosition = sf::Mouse::getPosition();
    windowPosition = window -> getPosition();

    a = mousePosition.x;
    b = mousePosition.y;

    angle = -(-atan2( a , b) * 180 + 180)/3.14159265359;


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if (angle < 0 && angle > -50){
            spriteh -> setRotation(angle);
            //arrow -> setRotation(angle);
        }
    }
    /*
    arrowComponents.x  = arrowSpeed*cos(30);
    arrowComponents.y =  arrowSpeed*sin(30) - 9.7*time;
    spritea -> setRotation(angle);
    spritea -> move(4 , 4 - 0.5*9.7* (time + 0.1));
    */
    window -> draw(*spriteh);
    window -> draw(*spriteb);
    }
