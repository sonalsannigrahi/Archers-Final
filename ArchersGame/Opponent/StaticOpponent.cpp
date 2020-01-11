#include "StaticOpponent.hpp"

StaticOpponent::StaticOpponent(Player* player, Texts* text){
    srand(time(NULL)); // Randomize
    this -> player = player;
    this -> text = text;
    filename = "arrow.png";
    sf::Texture* texture = new sf::Texture();
    health = statconstant.maxHealth;
    texture -> loadFromFile("Opponent/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("Opponent/Assets/defback.png");
    defback -> setTexture(*background);
    /*
    sf::Texture* heads = new sf::Texture();
    heads -> loadFromFile("Opponent/Assets/headshot.png");
    headshot -> setTexture(*heads); */
	sf::Texture* hand = new sf::Texture();
	hand -> loadFromFile("Opponent/Assets/hand_o.png");
	spriteh -> setTexture(*hand);
    spriteh -> setScale(0.25f,0.25f);
    spriteh -> setOrigin(float(spriteh -> getGlobalBounds().width) / 2,float(spriteh -> getGlobalBounds().height)/ 2);
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

    posX = -1;

    //HealthBar
    healthbar.setSize(sf::Vector2f(30,30));
    healthbar.setFillColor(sf::Color::Green);
}

void StaticOpponent::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void StaticOpponent::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    if (posX == -1){
        posX = rand()%(width/2) + float(width)/3;
        posY = -rand()%(height/3) + float(height)/2;
        for (int i =0; i < statconstant.filenamelen; i++){
            statSprites[i].setPosition(posX,posY);
        }
        spriteh -> setPosition(posX, posY + statSprites[0].getGlobalBounds().height / 4);
    }
    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void StaticOpponent::updateFrame(double time) {
    sf::Vector2i mousePosition;
    sf::Vector2i windowPosition;
    mousePosition = sf::Mouse::getPosition();
    windowPosition = window -> getPosition();

    counter = counter + time;
    if (counter >= statconstant.changetime){
        counter -= statconstant.changetime;
        current += 1;
        if (current >= statconstant.filenamelen){
            current = 0;
            //Shoot an arrow
            float dX = std::abs(spriteh -> getPosition().x - mousePosition.x + windowPosition.x);
            float dY = std::abs(spriteh -> getPosition().y - mousePosition.y + windowPosition.y);
            float power = rand()%1000 + 100;
            //float angle = -60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120)));
            float vX = - power;
            float vY = 0;
            createArrow(spriteh -> getPosition().x + spriteh -> getGlobalBounds().width / 2, spriteh -> getPosition().y + spriteh -> getGlobalBounds().height / 4, vX, vY);
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

    healthbar.setPosition(posX + 3, posY - 18);

    healthbar.setSize(sf::Vector2f((health/100)*60, 10));

    if (health <= 50){
        healthbar.setFillColor(sf::Color::Red);
    }
    
    if (alive) {
        hitboxHead.setPosition(posX + 18, posY);
        hitboxBody.setPosition(posX + 18, posY);
        if (isHitboxDrawn){
            window -> draw(hitboxBody);
            window -> draw(hitboxHead);
        }
        window -> draw(healthbar);
        window -> draw(statSprites[current]);
        window -> draw(*spriteh);
    }

}

void StaticOpponent::createArrow(float posX, float posY, float vX, float vY){
    //std::cout << posX << " " << posY << " " << vX << " " << vY << std::endl;
    Arrow* arrow = new Arrow(posX, posY, vX, vY, player, opponent, spear, statOpponent, text, filename);
    arrow -> setWindow(window);
    arrow -> setSize(windowWidth, windowHeight);
    arrows.push_back(arrow);
}

void StaticOpponent::removeArrow(int id){
    if (arrows.size() > id){
        delete arrows[id];
        arrows[id] = arrows[arrows.size() - 1];
        arrows.pop_back();
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

float StaticOpponent::getHealth(){
    return health;
}
