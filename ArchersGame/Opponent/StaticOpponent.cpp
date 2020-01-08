#include "StaticOpponent.hpp"
#include "../Character/bow.hpp"

StaticOpponent::StaticOpponent(Player* player){
    sf::Texture* texture = new sf::Texture();
    health = statconstant.maxHealth;
    texture -> loadFromFile("Opponent/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("Opponent/Assets/defback.png");
    defback -> setTexture(*background);
    for (int i = 0; i < statconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Opponent/Assets/"+ statconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        sprite -> setScale(0.4f * 5 / 6, 0.4f * 5 / 6);
        statSprites.push_back(*sprite);
    }
    // Hitbox
    hitboxBody.setSize(sf::Vector2f(30, 120));
    hitboxBody.setOutlineColor(sf::Color::Blue);
    hitboxBody.setOutlineThickness(5);
    
    hitboxHead.setSize(sf::Vector2f(30, 30));
    hitboxHead.setOutlineColor(sf::Color::Red);
    hitboxHead.setOutlineThickness(5);
}

void StaticOpponent::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void StaticOpponent::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    float angle = -60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120)));
    posX = rand()%(width/2) + float(width)/8;
    posY = -rand()%(height/3) + float(height)/2;
    for (int i =0; i < statconstant.filenamelen; i++){
      statSprites[i].setPosition(posX,posY);
    }
    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void StaticOpponent::updateFrame(double time) {
    counter = counter + time;
    if (counter >= statconstant.changetime){
        counter -= statconstant.changetime;
        current += 1;
        if (current >= statconstant.filenamelen) current = 0;
    }
    if (isHitboxDrawn){
            hitboxHead.setPosition(posX + 18, posY);
            hitboxBody.setPosition(posX + 18, posY);
            window -> draw(hitboxBody);
            window -> draw(hitboxHead);
    }
    if (alive){
        window -> draw(statSprites[current]);
    }
}
bool StaticOpponent::shoot(float x, float y){
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

bool StaticOpponent::isAlive(){
    return alive;
}
