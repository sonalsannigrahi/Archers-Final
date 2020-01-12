#include "Spear.hpp"

Spear::Spear(Player* player, Texts* text){
    srand(time(NULL));
    this -> player = player;
    this -> text = text; 
    filename = "spear.png";
    scale = 0.35;
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

    posX = -1;

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

    if (posX == -1){
        //float angle = -60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120)));
        posX = rand()%(width/2) + float(width)/3;
        posY = -rand()%(height/3) + float(height)/2;
        for (int i =0; i < spearconstant.filenamelen; i++){
            spearSprites[i].setPosition(posX,posY);
        }
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
      if (current >= spearconstant.filenamelen){ 
            float dX = std::abs(posX);
            float dY = std::abs(posY);
            float power = rand()%1000 + 100;
            float vX = - power;
            float vY = 0;
            createArrow(posX + spearSprites[current].getGlobalBounds().width / 2, posY + spearSprites[current].getGlobalBounds().height / 4, vX, vY);
            current = 0;
      }
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

void Spear::createArrow(float posX, float posY, float vX, float vY){
    Arrow* arrow = new Arrow(posX + 104, posY + 30, vX, vY, player, opponent, spear, statOpponent, text, filename, scale);
    arrow -> setWindow(window);
    arrow -> setSize(windowWidth, windowHeight);
    arrows.push_back(arrow);
}

void Spear::removeArrow(int id){
    if (arrows.size() > id){
        delete arrows[id];
        arrows[id] = arrows[arrows.size() - 1];
        arrows.pop_back();
    }
}

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

float Spear::getHealth(){
  return health;
}
