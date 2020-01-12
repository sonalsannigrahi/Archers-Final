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
    // Volume sliders
    for (int i = 0; i < 3; i++){
        volumeSlide[i] = new sf::RectangleShape();
        volumeButton[i] = new sf::CircleShape();
        volumeSlide[i] -> setSize(sf::Vector2f(500, 20));
        volumeSlide[i] -> setFillColor(sf::Color(240, 240, 240, 240));
        volumeSlide[i] -> setOutlineColor(sf::Color::Black);
        volumeSlide[i] -> setOutlineThickness(3);
        volumeButton[i] -> setRadius(15);
        volumeButton[i] -> setFillColor(sf::Color::Black);
    }
    // Background Sprites
    for (int i = 0; i < settingConstants.filename_length; i++){
        sf::Texture* bgtexture = new sf::Texture();
        bgtexture -> loadFromFile(settingConstants.filename[i], sf::IntRect(10, 10, 80, 150));
        backgroundPreviews[i] = new sf::Sprite(*bgtexture);
    }

    // Object Sprites
    sf::Texture* birdTexture = new sf::Texture();
    sf::Texture* rainTexture = new sf::Texture();
    sf::Texture* lightingTexture = new sf::Texture();
    sf::Texture* fireworksTexture = new sf::Texture();
    sf::Texture* balloonsTexture = new sf::Texture();

    birdTexture -> loadFromFile("Birds/Assets/bird2.png");
    rainTexture -> loadFromFile("Setting/Asset/rain.png");
    lightingTexture -> loadFromFile("Setting/Asset/lightning.png");
    fireworksTexture -> loadFromFile("Fireworks/asset/frame_apngframe9.png");
    balloonsTexture -> loadFromFile("Balloon/Asset/ballon2.png");
    birdTexture -> setSmooth(true);
    rainTexture -> setSmooth(true);
    lightingTexture -> setSmooth(true);
    fireworksTexture -> setSmooth(true);
    balloonsTexture -> setSmooth(true);
    objChoices[0] = new sf::Sprite(*birdTexture);
    objChoices[1] = new sf::Sprite(*rainTexture);
    objChoices[2] = new sf::Sprite(*lightingTexture);
    objChoices[3] = new sf::Sprite(*fireworksTexture);
    objChoices[4] = new sf::Sprite(*balloonsTexture);

    for (int i; i<5; i++){
        objChoices[i] -> setScale(sf::Vector2f(50/(objChoices[i] -> getGlobalBounds().width),50/(objChoices[i] -> getGlobalBounds().height)));
    }
/*
    if (game -> getIsBirds()){
        objChoices[0] -> setColor(sf::Color::Green);}
    if (game -> getIsRaining()){
        objChoices[1] -> setColor(sf::Color::Green);}
    if (game -> getIsLightning()){
        objChoices[2] -> setColor(sf::Color::Green);}
    if (game -> getIsFireworks()){
        objChoices[3] -> setColor(sf::Color::Green);}
    if (game -> getIsBalloons()){
        objChoices[4] -> setColor(sf::Color::Green);}
*/
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
    volumeGameValue.setFont(roboto_font);
    volumeMusicValue.setFont(roboto_font);
    volumeMasterValue.setFont(roboto_font);
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
    volumeMasterValue.setCharacterSize(30);
    volumeGameValue.setCharacterSize(30);
    volumeMusicValue.setCharacterSize(30);
    // Set text color
    title.setFillColor(sf::Color::Black);
    resolution.setFillColor(sf::Color::Blue);
    background.setFillColor(sf::Color::Blue);
    volumeMaster.setFillColor(sf::Color::Black);
    volumeGame.setFillColor(sf::Color::Black);
    volumeMusic.setFillColor(sf::Color::Black);        
    volumeGameValue.setFillColor(sf::Color::Black);
    volumeMasterValue.setFillColor(sf::Color::Black);
    volumeMusicValue.setFillColor(sf::Color::Black);
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
    for (int i = 0; i < 5;i++){
        objChoices[i] -> setPosition(settingScreenBound.left + 300 + i*80, settingScreenBound.top + 350);
    }
    volumeMaster.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 480);
    volumeGame.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 520);
    volumeMusic.setPosition(settingScreenBound.left + 15, settingScreenBound.top + 560);
    volumeMasterValue.setPosition(settingScreenBound.left + settingScreenBound.width - 100, settingScreenBound.top + 480);
    volumeGameValue.setPosition(settingScreenBound.left + settingScreenBound.width - 100, settingScreenBound.top + 520);
    volumeMusicValue.setPosition(settingScreenBound.left + settingScreenBound.width - 100, settingScreenBound.top + 560);
    volumeSlide[0] -> setPosition(settingScreenBound.left + 250, settingScreenBound.top + 490);
    volumeSlide[1] -> setPosition(settingScreenBound.left + 250, settingScreenBound.top + 530);
    volumeSlide[2] -> setPosition(settingScreenBound.left + 250, settingScreenBound.top + 570);
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
        volumeMasterValue.setString(std::to_string((int) game -> getMasterVolume()));
        volumeMusicValue.setString(std::to_string((int) game -> getBackgroundVolume()));
        volumeGameValue.setString(std::to_string((int) game -> getBirdsVolume()));
        // Check if volume is changed
        for (int i = 0; i < 3; i++)
            if (volumeSlide[i] -> getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
                //std::cout << "Hover above " << i << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    float volume = (float) (mousePosition.x - volumeSlide[i] -> getGlobalBounds().left) / volumeSlide[i] -> getGlobalBounds().width;
                    if (i == 0) game -> setMasterVolume(std::max(std::min(volume * 100, (float) 100), (float) 0));
                    if (i == 1){
                        game -> setRainVolume(std::max(std::min(volume * 100, (float) 100), (float) 0));
                        game -> setBirdsVolume(std::max(std::min(volume * 100, (float) 100), (float) 0));
                        game -> setThunderVolume(std::max(std::min(volume * 100, (float) 100), (float) 0));
                        game -> setFireworksVolume(std::max(std::min(volume * 100, (float) 100), (float) 0));
                    }
                    if (i == 2) game -> setBackgroundVolume(std::max(std::min(volume * 100, (float) 100), (float) 0));
                }
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
            } else resChoices[i].setFillColor(sf::Color::Black);
        // Check if backgroundPreview is hovered
        for (int i = 0; i < settingConstants.filename_length; i++)
            if (backgroundPreviews[i] -> getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
                backgroundPreviews[i] -> setScale(1.05, 1.05);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    game -> changeBackgroundPicture(i);
                }
            } else backgroundPreviews[i] -> setScale(1, 1);

        // Check if objects are hovered
        for (int i = 0; i < 5; i++)
            if (objChoices[i] -> getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if (!isMouseDown2[i]){
                        isMouseDown2[i] = true;
                        if (i==0) game -> toggleBirds();
                        if (i==1) game -> toggleRain();
                        if (i==2) game -> toggleLightning();  
                        if (i==3) game -> toggleFireworks();     
                        if (i==4) game -> toggleBalloons();
                    }
                } else isMouseDown2[i] = false;
            }
        if (game -> getIsBirds()){objChoices[0] -> setColor(sf::Color(255, 255, 255, 255));}
                        else {objChoices[0] -> setColor(sf::Color(255, 255, 255, 63));}
        if (game -> getIsRaining()){objChoices[1] -> setColor(sf::Color(255, 255, 255, 255));}
                        else {objChoices[1] -> setColor(sf::Color(255, 255, 255, 63));}
        if (game -> getIsLightning()){objChoices[2] -> setColor(sf::Color(255, 255, 255, 255));}
                        else {objChoices[2] -> setColor(sf::Color(255, 255, 255, 63));}
        if (game -> getIsFireworks()){objChoices[3] -> setColor(sf::Color(255, 255, 255, 255));}
                        else {objChoices[3] -> setColor(sf::Color(255, 255, 255, 63));}
        if (game -> getIsBalloons()){objChoices[4] -> setColor(sf::Color(255, 255, 255, 255));}
                        else {objChoices[4] -> setColor(sf::Color(255, 255, 255, 63));}

        window -> draw(*settingScreen);
        // Draw text
        window -> draw(title);
        //window -> draw(resolution);
        //window -> draw(background);
        //window -> draw(birds);
        //window -> draw(rain);
        //window -> draw(lightning);
        //window -> draw(balloons);
        //window -> draw(fireworks);
        window -> draw(volumeMaster);
        window -> draw(volumeGame);
        window -> draw(volumeMusic);
        window -> draw(volumeMasterValue);
        window -> draw(volumeGameValue);
        window -> draw(volumeMusicValue);
        // Draw slides
        for (int i = 0; i < 3; i++) window -> draw(*volumeSlide[i]);
        volumeButton[0] -> setPosition(volumeSlide[0] -> getGlobalBounds().left + volumeSlide[0] -> getGlobalBounds().width * (game -> getMasterVolume() / 100) - 15, volumeSlide[0] -> getGlobalBounds().top - 2);
        window -> draw(*volumeButton[0]);
        volumeButton[1] -> setPosition(volumeSlide[1] -> getGlobalBounds().left + volumeSlide[1] -> getGlobalBounds().width * (game -> getBirdsVolume() / 100) - 15, volumeSlide[1] -> getGlobalBounds().top - 2);
        window -> draw(*volumeButton[1]);
        volumeButton[2] -> setPosition(volumeSlide[2] -> getGlobalBounds().left + volumeSlide[2] -> getGlobalBounds().width * (game -> getBackgroundVolume() / 100) - 15, volumeSlide[2] -> getGlobalBounds().top - 2);
        window -> draw(*volumeButton[2]);
        // Draw resolution
        for (int i = 0; i < 4; i++) window -> draw(resChoices[i]);
        for (int i = 0; i < settingConstants.filename_length; i++) window -> draw(*backgroundPreviews[i]);
        for (int i = 0; i < 5; i++) window -> draw(*objChoices[i]);
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


