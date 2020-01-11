#include"Setting.hpp"
#include "../Game/Game.hpp"

Setting::Setting(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Setting/Asset/" + settingConstants.settingButtonImage);
    settingButton = new sf::Sprite(*texture);
    settingButton -> setScale(settingConstants.scale, settingConstants.scale);
    settingScreen -> setFillColor(sf::Color(240, 240, 240, 240));
    settingScreen -> setOutlineColor(sf::Color::Black);
    settingScreen -> setOutlineThickness(5);
    // Background Sprites
    for (int i = 0; i < settingConstants.filename_length; i++){
        sf::Texture* bgtexture = new sf::Texture();
        bgtexture -> loadFromFile(settingConstants.filename[i], sf::IntRect(10, 10, 80, 150));
        backgroundPreviews[i] = new sf::Sprite(*bgtexture);
    }
    // Set 
    //loading font
    if (!font.loadFromFile(settingConstants.fontfile))
    {
        std::cout << "Error text file" << std::endl;
    }
    if (!roboto_font.loadFromFile(settingConstants.robotofile))
    {
        std::cout << "Error text file" << std::endl;
    }
    //Set font
    title.setFont(font);
    resolution.setFont(roboto_font);
    background.setFont(roboto_font);
    birds.setFont(font);
    rain.setFont(font);
    lightning.setFont(font);
    fireworks.setFont(font);
    balloons.setFont(font);
    volumeMaster.setFont(roboto_font);
    volumeMusic.setFont(roboto_font);
    volumeGame.setFont(roboto_font);
    for (int i = 0; i < 4; i++){
        resChoices[i].setFont(roboto_font);
    }
    //Set string 
    title.setString("SETTINGS");
    resolution.setString("Resolution");
    background.setString("Background");
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
    title.setCharacterSize(60);
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
    title.setFillColor(sf::Color::Black);
    resolution.setFillColor(sf::Color::Blue);
    background.setFillColor(sf::Color::Blue);
    volumeMaster.setFillColor(sf::Color::Black);
    volumeGame.setFillColor(sf::Color::Black);
    volumeMusic.setFillColor(sf::Color::Black);
}

void Setting::setWindow(sf::RenderWindow* window){
    this -> window = window;
}

void Setting::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    settingButton -> setPosition(windowWidth - settingButton -> getGlobalBounds().width, 0.0);
    settingScreen -> setSize(sf::Vector2f((float) 900,(float) 600));
    settingScreen -> setPosition(sf::Vector2f((float)(windowWidth - 900) / 2, (float) (windowHeight - 600) / 2));
    //Set position
    sf::FloatRect settingScreenBound = settingScreen -> getGlobalBounds();
    title.setPosition(settingScreenBound.left + (settingScreenBound.width - title.getGlobalBounds().width) / 2, settingScreenBound.top + 5);
    resolution.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 100);
    for (int i = 0; i < 4; i++)
        resChoices[i].setPosition(resolution.getGlobalBounds().left + 50 + 200 * i, resolution.getGlobalBounds().top - 8);
    background.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 200);
    for (int i = 0; i < settingConstants.filename_length; i++)
        backgroundPreviews[i] -> setPosition(settingScreenBound.left + 27 + i * 85, settingScreenBound.top + 170);
    volumeMaster.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 480);
    volumeGame.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 520);
    volumeMusic.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 560);
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
            } else resChoices[i].setFillColor(sf::Color::Black);
        // Check if backgroundPreview is hovered
        for (int i = 0; i < settingConstants.filename_length; i++)
            if (backgroundPreviews[i] -> getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
                backgroundPreviews[i] -> setScale(1.05, 1.05);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    game -> changeBackgroundPicture(i);
                }
            } else backgroundPreviews[i] -> setScale(1, 1);

        window -> draw(*settingScreen);
        // Draw text
        window -> draw(title);
        //window -> draw(resolution);
        //window -> draw(background);
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
        for (int i = 0; i < settingConstants.filename_length; i++) window -> draw(*backgroundPreviews[i]);
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


