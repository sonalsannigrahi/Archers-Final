#include "Opponent.hpp"
#include "../Character/bow.hpp"

Opponent::Opponent(Player* player){
    this -> player = player;
    health = charconstant.maxHealth;
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Opponent/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("Opponent/Assets/defback.png");
    defback -> setTexture(*background);
    for (int i = 0; i < charconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Opponent/Assets/"+ charconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        if (i == 0) 
            sprite -> setScale(0.4f * 5 / 6, 0.4f * 5 / 6);
        else // Set all sprite to the same size
            sprite -> setScale(oppSprites[oppSprites.size() - 1].getGlobalBounds().width / sprite -> getGlobalBounds().width, 
                                oppSprites[oppSprites.size() - 1].getGlobalBounds().height / sprite -> getGlobalBounds().height);
        oppSprites.push_back(*sprite);
    }
    posX = -1.0;

    // Hitbox
    hitboxBody.setSize(sf::Vector2f(30, 120));
    hitboxBody.setOutlineColor(sf::Color::Blue);
    hitboxBody.setOutlineThickness(5);
    
    hitboxHead.setSize(sf::Vector2f(30, 30));
    hitboxHead.setOutlineColor(sf::Color::Red);
    hitboxHead.setOutlineThickness(5);

    //Healthbar
    healthbar.setSize(sf::Vector2f(30,30));
    healthbar.setFillColor(sf::Color::Green);    

}

void Opponent::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Opponent::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    if (posX == -1.0) posX = width - float(width)/25; // set to opposite end of window
    posY = float(height)/1.8;
    comparison = float(width)/25;
    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void Opponent::updateFrame(double time) {
    counter = counter + time;
    if (counter >= charconstant.changetime ) {
        counter -= charconstant.changetime;
        current += 1;
        current %= charconstant.filenamelen;
    }

    if (direction == 0){
        posX -= charconstant.charSpeed * time; // run in left direction
    } else {
        posX += charconstant.charSpeed * time;
    }

    //std::cout << posX << " " << posY << std::endl;

    if (posX < comparison + 30 || posX > (float) windowWidth || health <= 0){
        alive = false; // sprite has reached out of window

        // If hit the player
        if (posX < comparison + 30 && health > 0){
            player -> stab();
        }

        // window -> draw(*defback); //semi transparent black screen, maybe call game pause
        // window -> draw(*defeat); // can be removed, defeat screen
    } else {
        // Draw hitbox
        hitboxHead.setPosition(posX + 12, posY);
        hitboxBody.setPosition(posX + 12, posY);
        if (isHitboxDrawn){
            window -> draw(hitboxBody);
            window -> draw(hitboxHead);
        }
        healthbar.setPosition(posX, posY - 18);

        healthbar.setSize(sf::Vector2f((health/100)*60, 10));

        if (health <= 50){
            healthbar.setFillColor(sf::Color::Red);
        }

        window -> draw(healthbar);
  
        oppSprites[current].setPosition(posX, posY);
        window -> draw(oppSprites[current]);
    }
}

bool Opponent::shoot(float x, float y){
    if (hitboxHead.getPosition().x <= x && x <= hitboxHead.getPosition().x + hitboxHead.getSize().x &&
        hitboxHead.getPosition().y <= y && y <= hitboxHead.getPosition().y + hitboxHead.getSize().y){
            health -= 100;
            return true;
        } else if (hitboxBody.getPosition().x <= x && x <= hitboxBody.getPosition().x + hitboxBody.getSize().x &&
                    hitboxBody.getPosition().y <= y && y <= hitboxBody.getPosition().y + hitboxBody.getSize().y){
                        health -= 70;
                        return true;
                    }
    return false;
}

bool Opponent::isAlive(){
    return alive;
}

float Opponent::getHealth(){
    return health;
}