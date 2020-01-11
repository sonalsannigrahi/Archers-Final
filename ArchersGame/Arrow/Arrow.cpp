#include "Arrow.hpp"
#include "../Opponent/Opponent.hpp"
#include "../Opponent/Spear.hpp"
#include "../Character/bow.hpp"
#include "../Opponent/StaticOpponent.hpp"

Arrow::Arrow(){
    // This function is for testing purpose only

    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Arrow/Assets/" + arrowConstants.filename);
    arrowSprite = new sf::Sprite(*texture); 
    arrowSprite -> setScale(arrowConstants.scale, arrowConstants.scale);

    posX = 10;
    posY = 400;
    vX = 400;
    vY = -200;

    // Hitbox
    hitbox.setSize(sf::Vector2f(2, 2));
    hitbox.setOutlineColor(sf::Color::Blue);
    hitbox.setOutlineThickness(5);
}

Arrow::Arrow(float posX, float posY, float vX, float vY, Player* player, std::vector<Opponent*>* opponent, std::vector<Spear*>* spear, std::vector<StaticOpponent*>* statico, Texts* texts){
    this -> texts = texts;
    this -> player = player;
    this -> opponent = opponent;
    this -> statico = statico;
    this -> spear = spear;

    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Arrow/Assets/" + arrowConstants.filename);
    arrowSprite = new sf::Sprite(*texture); 
    arrowSprite -> setScale(arrowConstants.scale, arrowConstants.scale);

    this -> posX = posX;
    this -> posY = posY;
    this -> vX = vX;
    this -> vY = vY;

    // Hitbox
    hitbox.setSize(sf::Vector2f(2, 2));
    hitbox.setOutlineColor(sf::Color::Blue);
    hitbox.setOutlineThickness(5);
}

Arrow::Arrow(float posX, float posY, float vX, float vY, Player* player, std::vector<Opponent*>* opponent, std::vector<Spear*>* spear, std::vector<StaticOpponent*>* statico, Texts* texts, std::string filename){
    this -> texts = texts;
    this -> player = player;
    this -> opponent = opponent;
    this -> statico = statico;
    this -> spear = spear;

    arrowConstants.filename = filename;

    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Arrow/Assets/" + arrowConstants.filename);
    arrowSprite = new sf::Sprite(*texture); 
    arrowSprite -> setScale(arrowConstants.scale, arrowConstants.scale);

    this -> posX = posX;
    this -> posY = posY;
    this -> vX = vX;
    this -> vY = vY;

    // Hitbox
    hitbox.setSize(sf::Vector2f(2, 2));
    hitbox.setOutlineColor(sf::Color::Blue);
    hitbox.setOutlineThickness(5);
}

void Arrow::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
}

void Arrow::setWindow(sf::RenderWindow* gameWindow){
    this -> window = gameWindow;
}

bool Arrow::isAlive(){
    return alive;
}

void Arrow::updateFrame(double time){
    vY += arrowConstants.gravity * time;
    posX += vX * time;
    posY += vY * time;
    angle = atan2(vY, vX) * 180 / 3.14159265359;
    

    if (posX >= 0 && posX <= windowWidth && posY >= 0 && posY <= windowHeight){
        //std::cout << 1 << std::endl;
        
        arrowSprite -> setPosition(posX, posY);
        arrowSprite -> setRotation(angle);
        window -> draw(*arrowSprite);

        if (angle < 0) angle += 360;

        //std::cout << 2 << std::endl;

        // Arrow head
        float headX, headY;
        if (angle > 90 && angle <= 270) headX = posX - arrowSprite -> getGlobalBounds().width; else headX = posX + arrowSprite -> getGlobalBounds().width;
        if (angle <= 180) headY = posY + arrowSprite -> getGlobalBounds().height; else headY = posY - arrowSprite -> getGlobalBounds().height;

        //std::cout << 3 << std::endl;

        // Draw hitbox
        if (isHitboxDrawn){
            hitbox.setPosition(headX, headY);
            window -> draw(hitbox);
        }

        //std::cout << 4 << std::endl;

        // Check if arrow hit something
        if (alive && (texts->bruh == 1) && texts->loadgame(headX, headY)) alive = false;
        //std::cout << 5 << std::endl;
        if (alive && texts ->box_hit(headX,headY)) alive = false;
        //std::cout << 6 << std::endl;
        for (int i = 0; i < opponent -> size(); i++){
            if (alive && (*opponent)[i] -> shoot(headX, headY)) alive = false;   
        }
        //std::cout << 7 << std::endl;
        for (int i = 0; i < statico -> size(); i++){
            if (alive && (*statico)[i] -> shoot(headX, headY)) alive = false;
        }
        //std::cout << 8 << std::endl;
        for (int i = 0; i < spear -> size(); i++){
            if (alive && (*spear)[i] -> shoot(headX, headY)) alive = false;
        }
        //std::cout << 9 << std::endl;
        if (alive && player -> shoot(headX, headY)) alive = false;

        //std::cout << 10 << std::endl;
    }
     else {
        alive = false;
    }
}
