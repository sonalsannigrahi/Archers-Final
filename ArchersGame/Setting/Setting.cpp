#include"Setting.hpp"
#include "../Game/Game.hpp"

Setting::Setting(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Setting/Asset/" + settingConstants.settingButtonImage);
    settingButton = new sf::Sprite(*texture);
    settingButton -> setScale(settingConstants.scale, settingConstants.scale);
    settingScreen -> setFillColor(sf::Color(173, 216, 230, 255));
    settingScreen -> setOutlineColor(sf::Color::Black);
    settingScreen -> setOutlineThickness(5);
    // Set 
    //loading font
    if (!font.loadFromFile(settingConstants.fontfile))
    {
        std::cout << "Error text file" << std::endl;
    }
    //Set font
    title.setFont(font);
    resolution.setFont(font);
    background.setFont(font);
    birds.setFont(font);
    rain.setFont(font);
    lightning.setFont(font);
    fireworks.setFont(font);
    balloons.setFont(font);
    volumeMaster.setFont(font);
    volumeMusic.setFont(font);
    volumeGame.setFont(font);
    for (int i = 0; i < 4; i++){
        resChoices[i].setFont(font);
    }
    //Set string 
    title.setString("SETTINGS");
    resolution.setString("Choose resolution");
    background.setString("Choose Background");
    birds.setString("Birds");
    rain.setString("Rain");
    lightning.setString("Lightning");
    fireworks.setString("Fireworks");
    balloons.setString("Balloons");
    volumeMaster.setString("Master Volume");
    volumeGame.setString("Game Volume");
    volumeMusic.setString("Music Volume");
    resChoices[0].setString("900x600");
    resChoices[1].setString("1024x768");
    resChoices[2].setString("1366x768");
    resChoices[3].setString("1920x1080");
    //Set character size
    title.setCharacterSize(100);
    resolution.setCharacterSize(30);
    background.setCharacterSize(30);
    birds.setCharacterSize(30);
    rain.setCharacterSize(30);
    lightning.setCharacterSize(30);
    fireworks.setCharacterSize(30);
    balloons.setCharacterSize(30);
    volumeMaster.setCharacterSize(30);
    volumeGame.setCharacterSize(30);
    volumeMusic.setCharacterSize(30);
    for (int i = 0; i < 4; i++){
        resChoices[i].setCharacterSize(30);
    }
    // Set text color
}

void Setting::setWindow(sf::RenderWindow* window){
    this -> window = window;
}

void Setting::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    settingButton -> setPosition(windowWidth - settingButton -> getGlobalBounds().width, 0.0);
    settingScreen -> setSize(sf::Vector2f((float) windowWidth/2,(float) windowHeight/2));
    settingScreen -> setPosition(sf::Vector2f((float)windowWidth/4, (float) windowHeight/4));
    //Set position
    resChoices[0].setPosition(width / 3, height / 3);
    resChoices[1].setPosition(width / 2, height / 2);
}

void Setting::setGame(Game* game){  
    this -> game = game;
}

void Setting::updateFrame(double time){
    window -> draw(*settingButton);
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if (settingButton -> getGlobalBounds().contains(mousePosition.x, mousePosition.y) && !isMouseDown){
            if(game -> getIsGamePaused()){
                game -> unpauseGame();
            }
            else{
                game -> pauseGame();
            }
        }
        isMouseDown = true;
    } else isMouseDown = false;
    //std::cout << isMouseDown <<std::endl;

    if (game -> getIsGamePaused()){
        // Set resolution color
        for (int i = 0; i < 4; i++){
            resChoices[i].setFillColor(sf::Color::Black);
        }
        // Check if resolution is hovered
        for (int i = 0; i < 4; i++) 
            if (resChoices[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
                resChoices[i].setFillColor(sf::Color::Blue);
                //std::cout << "Hover above " << i << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if (i == 0) game -> setWindowSize(900, 600);
                    if (i == 1) game -> setWindowSize(1024, 768);
                    if (i == 2) game -> setWindowSize(1366, 768);
                    if (i == 3) game -> setWindowSize(1920, 1080);
                }
            }

        window -> draw(*settingScreen);
        // Draw text
        window -> draw(title);
        window -> draw(resolution);
        window -> draw(background);
        window -> draw(birds);
        window -> draw(rain);
        window -> draw(lightning);
        window -> draw(balloons);
        window -> draw(fireworks);
        window -> draw(volumeMaster);
        window -> draw(volumeGame);
        window -> draw(volumeMusic);
        // Draw resolution
        for (int i = 0; i < 4; i++) window -> draw(resChoices[i]);
    }
    /*
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    // transform the mouse position from window coordinates to world coordinates
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);

    // retrieve the bounding box of the sprite
    sf::FloatRect bounds = settingButton.getGlobalBounds();

    // hit test
    if (settingButton.contains(localPosition))
    {
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        window.draw(rectangle);
    }
}
        }
    //}
    // Ex
    //std::cout << game -> getFireworksRate() << std::endl;
    //game -> setFireworksRate(std::max((float) 1.0, (float) game -> getFireworksRate() - (float) time / 100));
    //game -> toggleBalloons();
*/
}


