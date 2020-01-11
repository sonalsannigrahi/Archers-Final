#include "bow.hpp"

Player::Player(std::vector<Opponent*>* opponent, std::vector<Spear*>* spear, std::vector<StaticOpponent*>* statico, Texts* texts){
    this -> texts = texts;
    this -> opponent = opponent;
    this -> statico = statico;
    this -> spear = spear;
    filename = "arrow.png";
    health = maxHealth;
    //creating three textures for the arm, body, arrow
	sf::Texture* body = new sf::Texture();
	body -> loadFromFile("Character/charac_arm.png");
	spriteb -> setTexture(*body);
	sf::Texture* hand = new sf::Texture();
	hand -> loadFromFile("Character/hand_p.png");
	spriteh -> setTexture(*hand);

    // Hitbox
    hitboxBody.setSize(sf::Vector2f(30, 120));
    hitboxBody.setOutlineColor(sf::Color::Blue);
    hitboxBody.setOutlineThickness(5);
    
    hitboxHead.setSize(sf::Vector2f(30, 30));
    hitboxHead.setOutlineColor(sf::Color::Red);
    hitboxHead.setOutlineThickness(5);

    //HealthBar
    healthbar.setSize(sf::Vector2f(30,30));
    healthbar.setFillColor(sf::Color::Green);
}


void Player::setWindow(sf::RenderWindow* gameWindow){
    //set window to game window
	window = gameWindow;
}

void Player::setSize(int width, int height ){
    winWidth = width;
	winHeight = height;
    for (int i = 0; i < arrows.size(); i++){
        arrows[i] -> setSize(width, height);
    }
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

    spriteh -> setOrigin(float(handSize.width) / 2,float(handSize.height)/ 2);

    spriteb -> setPosition(float(winWidth)/25, float(winHeight)/1.8);      

    spriteh -> setPosition(spriteb -> getPosition().x + float(bodySize.width)/3 ,spriteb -> getPosition().y + float(bodySize.height)/4);
    
    playerPosition = spriteh -> getPosition();
    /*
    arrowSpeed = 2;
    spritea -> setPosition(spriteh -> getPosition().x, spriteh -> getPosition().y);
    */

    spriteh -> setRotation(0);

    hitboxHead.setPosition(spriteb -> getPosition().x + 15, spriteb -> getPosition().y + 5);
    hitboxBody.setPosition(spriteb -> getPosition().x + 15, spriteb -> getPosition().y + 5);

    mousePosition = sf::Mouse::getPosition();
    windowPosition = window -> getPosition();

    a = mousePosition.x - windowPosition.x;
    b = mousePosition.y - windowPosition.y;

    angle = -(-atan2( a , b) * 180 + 180)/3.14159265359;


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if (angle < 0 && angle > -55){
            spriteh -> setRotation(angle);
            lastAngle = angle;
            lastPower += time;
            //arrow -> setRotation(angle);
        }
    } else {
        if (lastAngle != NULL){
            float dX = std::abs(spriteh -> getPosition().x - mousePosition.x + windowPosition.x);
            float dY = std::abs(spriteh -> getPosition().y - mousePosition.y + windowPosition.y);
            float power = lastPower * 1000 + 100;
            float vX = power * std::cos(lastAngle * 3.14159265359 / 180);
            float vY = power * std::sin(lastAngle * 3.14159265359 / 180);
            createArrow(spriteh -> getPosition().x + spriteh -> getGlobalBounds().width / 2, spriteh -> getPosition().y + spriteh -> getGlobalBounds().height / 4, vX, vY);
        }
        lastAngle = NULL;
        lastPower = 0;
    }

    // Draw arrows
    if (arrows.size() > 0){
        int id = 0;
        while (id < arrows.size()){
            if (arrows[id] -> isAlive()){
                arrows[id] -> updateFrame(time);
                id++;
            }
            else removeArrow(id);
        }
    }

    if (isHitboxDrawn){
        window -> draw(hitboxBody);
        window -> draw(hitboxHead);
    };


    healthbar.setPosition(playerPosition.x - 20, playerPosition.y - 50);

    healthbar.setSize(sf::Vector2f((health/100)*60, 10));

    if (health <= 50){
      healthbar.setFillColor(sf::Color::Red);
    }
    if (health >= 0){
        window -> draw(healthbar);
    }

    window -> draw(*spriteh);
    window -> draw(*spriteb);
}

void Player::createArrow(float posX, float posY, float vX, float vY){
    Arrow* arrow = new Arrow(posX, posY, vX, vY, this, opponent, spear, statico, texts, filename);
    arrow -> setWindow(window);
    arrow -> setSize(winWidth, winHeight);
    arrows.push_back(arrow);
}

void Player::removeArrow(int id){
    if (arrows.size() > id){
        delete arrows[id];
        arrows[id] = arrows[arrows.size() - 1];
        arrows.pop_back();
    }
}

bool Player::shoot(float x, float y){
    if (hitboxHead.getPosition().x <= x && x <= hitboxHead.getPosition().x + hitboxHead.getSize().x &&
        hitboxHead.getPosition().y <= y && y <= hitboxHead.getPosition().y + hitboxHead.getSize().y){
            health -= 50;
            return true;
        } else if (hitboxBody.getPosition().x <= x && x <= hitboxBody.getPosition().x + hitboxBody.getSize().x &&
                    hitboxBody.getPosition().y <= y && y <= hitboxBody.getPosition().y + hitboxBody.getSize().y){
                        health -= 35;
                        return true;
                    }
    return false;
}

void Player::stab(){
    health -= 70;
}

void Player::pierced(float x, float y){
    health -= 100;
}

void Player::resetHealth(){
    health = maxHealth;
    healthbar.setFillColor(sf::Color::Green);
}

float Player::getHealth(){
    return health;
}
