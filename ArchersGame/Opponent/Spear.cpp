#include "Spear.hpp"
#include "../Character/bow.hpp"

Spear::Spear(Player* player){
    sf::Texture* texture = new sf::Texture();
    health = spearconstant.maxHealth;
    texture -> loadFromFile("Opponent/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("Opponent/Assets/defback.png");
    defback -> setTexture(*background);
    for (int i = 0; i < spearconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Opponent/Assets/"+ spearconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        sprite -> setScale(0.65f,0.65f);
        spearSprites.push_back(*sprite);
    }
    // Hitbox
    hitboxBody.setSize(sf::Vector2f(40, 78));
    hitboxBody.setOutlineColor(sf::Color::Blue);
    hitboxBody.setOutlineThickness(5);
    
    hitboxHead.setSize(sf::Vector2f(30, 30));
    hitboxHead.setOutlineColor(sf::Color::Red);
    hitboxHead.setOutlineThickness(5);

    //HealthBar
    healthbar.setSize(sf::Vector2f(30,30));
    healthbar.setFillColor(sf::Color::Green);
}

void Spear::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Spear::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    float angle = -60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120)));
    posX = rand()%(width/2) + float(width)/8;
    posY = -rand()%(height/3) + float(height)/2;
    for (int i =0; i < spearconstant.filenamelen; i++){
      spearSprites[i].setPosition(posX,posY);
    }
    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void Spear::updateFrame(double time) {
    counter = counter + time;
    if (counter >= spearconstant.changetime){
      counter -= spearconstant.changetime;
      current += 1;
      if (current >= spearconstant.filenamelen) current = 0;
    }
  
    if (health <= 0){
      alive = false;
    }

    healthbar.setPosition(posX + 85, posY + 10);

    healthbar.setSize(sf::Vector2f((health/100)*60, 10));

    if (health <= 50){
      healthbar.setFillColor(sf::Color::Red);
    }

    if (alive) {
      hitboxHead.setPosition(posX + 100 , posY + 30);
      hitboxBody.setPosition(posX + 100, posY + 60);
      if (isHitboxDrawn){
        window -> draw(hitboxBody);
        window -> draw(hitboxHead);
      }
      window -> draw(healthbar);
      window -> draw(spearSprites[current]);
    }

};

bool Spear::shoot(float x, float y){
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

bool Spear::isAlive(){
    return alive;
}
