#include "Game.hpp"

Game::Game(){
    srand(time(NULL)); // Randomize
    gameConstants.isRunning = false;
    // Create game window
    sf::VideoMode videoMode = sf::VideoMode(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    window = new sf::RenderWindow(videoMode, "Archers");
    //Username
    
    // Send window to other classes
    gameBackground.setWindow(window);
    gameWater.setWindow(window);
    gameLightning.setWindow(window);
    gameRain.setWindow(window);
    text.setWindow(window);
    player -> setWindow(window);
    gameSetting.setWindow(window);
    //arrow.setWindow(window);
    endgame.setWindow(window);

    // Inititalize window size
    gameBackground.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameWater.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameLightning.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameRain.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    text.setWindowSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    player -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameSetting.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    //arrow.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    endgame.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);

    // Send a pointer to game class
    gameSetting.setGame(this);

    // Set initialize volume
    gameBackground.changeBackgroundVolume(gameConstants.backgroundVolume * gameConstants.masterVolume);
    gameRain.change_volume_rain(gameConstants.rainVolume * gameConstants.masterVolume);
    gameLightning.change_volume_lightning(gameConstants.thunderVolume * gameConstants.masterVolume);

    // Set background
    changeBackgroundPicture(enc -> get_item<int>("background"));

    // Start rain audio
    if (gameConstants.isRaining) gameRain.playAudio();

    // Start game
    std::cout << "Starting Game ..." << std::endl;
    StartGame();
}

Game::~Game(){
}

void Game::StartGame(){
    // CIRCLE TEST

    // Draw a circle
    // circle = new sf::CircleShape(100.f);
    // circle -> setFillColor(sf::Color::Green);

    // END CIRCLE TEST

    // TEST BIRDS

    // createBird();
    
    // END TEST BIRDS

    // if game has ended

    // Start timer
    elapsedTime = clock();

    // Update Frame
    std::cout << "Game started ..." << std::endl;
    while (window -> isOpen())
    {
        sf::Event event;
        while (window -> pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window -> close();
            else if (text.bruh==-1 && event.type == sf::Event::TextEntered){
                if(event.text.unicode >=32 &&  event.text.unicode <= 126){
                    UserName += (char)event.text.unicode;
                }
                else if (event.text.unicode ==8 && UserName.getSize()>0){
                    UserName.erase(UserName.getSize()-1,UserName.getSize());
                }
                
            }

            else if (event.type == sf::Event::KeyPressed){
                if(text.bruh==-1 && event.key.code == sf::Keyboard::Return ){
                    if(UserName.getSize() == 0){
                        UserName = "New Player";
                        text.bruh = 1;
                    }
                    else{
                        text.bruh = 1;
                    }
                }
                else if (event.key.code == sf::Keyboard::Escape){
                    // TEST KEY PRESSED
                    // std::cout << "The escape key is pressed" << std::endl;
                    // std::cout << "control: " << event.key.control << std::endl;
                    // std::cout << "shift: " << event.key.shift << std::endl;
                    // std::cout << "alt: " << event.key.alt << std::endl;
                    // std::cout << "system: " << event.key.system << std::endl;

                    if (isGamePaused) unpauseGame(); else pauseGame();
                    std::cout << "Game paused!" << std::endl;
                }
            
            }
        }

        window -> clear();
        UpdateFrame();
        window -> display();
    }
}

void Game::UpdateFrame(){
    // std::cout << "Updating Frame at " << double(elapsedTime) / CLOCKS_PER_SEC << std::endl;
    
    

    // Calculate time has passed since the last UpdateFrame
    if(!gameConstants.isRunning){
        gameConstants.isOpponent = false;
    }
    double time = 0;
    if (!isGamePaused) time = double(clock() - elapsedTime) / CLOCKS_PER_SEC;
    elapsedTime = clock();

    // Check if the screen resolution has changed
    sf::Vector2u resolution = window -> getSize();
    //std::cout << resolution.x << ' ' << resolution.y << '\n';
    if (window -> getSize().x != gameConstants.WINDOW_WIDTH || window -> getSize().y != gameConstants.WINDOW_HEIGHT)
        setWindowSize(resolution.x, resolution.y);

    cout<<text.bruh<<endl;
    if (text.bruh==-1){
        text.updateFrame(time);
        sf::Text name = sf::Text( UserName, text.font, 20);
        int lettersnumber = UserName.getSize();
        name.setPosition(gameConstants.WINDOW_WIDTH/2- lettersnumber*(7,5),5*gameConstants.WINDOW_HEIGHT/16 + 60);
        window->draw(name);
    }
    else {
    // Spawn Rate Decay - Increase difficulty
    gameConstants.opponentRate = max(0.1, gameConstants.opponentRate - gameConstants.opponentRateDecay * time);
    gameConstants.staticOpponentRate = max(0.1, gameConstants.staticOpponentRate - gameConstants.staticOpponentRateDecay * time);
    gameConstants.spearRate = max(0.1, gameConstants.spearRate - gameConstants.spearRateDecay * time);


    // Creating birds
    if ((((double) rand() / RAND_MAX) * gameConstants.birdRate < time) && gameConstants.isBirds) {
        //std::cout << rand() << ' ' << RAND_MAX << ' ' << ((double) rand() / RAND_MAX) * gameConstants.birdRate << ' ' << time << ' ' << (((double) rand() / RAND_MAX) * gameConstants.birdRate < time) << '\n';
        createBird();
    }

    // Creating balloons
    if ((((double) rand() / RAND_MAX) * gameConstants.balloonRate < time) && gameConstants.isBalloon)
        createBalloon();

    // Creating Fireworks
    if ((((double) rand() / RAND_MAX) * gameConstants.fireworkRate < time) && gameConstants.isFireworks) 
        createFireworks();
    
    //Creating Opponent
    if ((((double) rand() / RAND_MAX) * gameConstants.opponentRate < time) && gameConstants.isOpponent) 
        createOpponent();

    //std::cout << rand() << " " << RAND_MAX << std::endl;

    // Draw Background
    gameBackground.updateFrame(time);
    //std::cout << "Yo i was here" << std::endl;

    // Draw Lightning
    if (gameConstants.isLightning) gameLightning.updateFrame(time);

    //Draw Fireworks
    if (gameConstants.isFireworks){
        int id = 0;
        while (id < fireworks.size()){
            if (fireworks[id] -> isAlive()){
                fireworks[id] -> updateFrame(time);
                id ++;
            }
            else removeFireworks(id);
        }
    }

    // Draw birds
    if (gameConstants.isBirds){
        int id = 0;
        while (id < birds.size()){
            if (birds[id] -> isAlive()){
                birds[id] -> updateFrame(time);
                id++;
            }
            else removeBird(id);
        }
    }

    // Draw balloons
    if (gameConstants.isBalloon){
        int id = 0;
        //std::cout << balloons.size();
        while (id < balloons.size()){
            if (balloons[id] -> isActive()){
                balloons[id] -> updateFrame(time);
                id++;
            }
            else removeBalloon(id);
        }
    }

    // Draw Rain
    if (gameConstants.isRaining) gameRain.updateFrame(time);

    // Draw Player
    if(text.bruh == 0 || text.bruh == 2){
        player -> updateFrame(time);
    }
    //Draw text
    text.updateFrame(time);


    // Draw Opponents
    if (opponent.size() > 0){
        int id = 0;
        while (id < opponent.size()){
            if (opponent[id] -> isAlive()){
                opponent[id] -> updateFrame(time);
                id++;
            }
            else removeOpponent(id);
        }
    }

    // Draw Arrow (test)
    // arrow.updateFrame(time);

    // Draw Water
    gameWater.updateFrame(time);

    // Draw Setting
    gameSetting.updateFrame(time);
    
    // Update FPS counter
    gameFPS.UpdateFPS(double(elapsedTime) / CLOCKS_PER_SEC);
    //std::cout << window -> getView().getSize().x << ' ' << window -> getView().getSize().y << '\n';
    if (!isGamePaused) std::cout << "Game is running at " << gameFPS.GetFPS() << " fps" << '\r';

    // CIRCLE TEST

    // Change circle's color
    // circle -> setFillColor(sf::Color(0, 255, 0, int((double (elapsedTime) / CLOCKS_PER_SEC) * 25) % 256));
    // window -> draw(*circle);
    
    // std::cout << "Yo i was here" << std::endl;
     
    // END CIRCLE TEST

    // Print cursor position
    // For testing / debuging purpose ONLY

    // // Get mouse position
    // sf::Vector2i positionMouse = sf::Mouse::getPosition();
    // sf::Vector2i positionWindow = window -> getPosition();

    // // Print
    // std::cout << std::to_string(positionMouse.x - positionWindow.x) + ", " + std::to_string(positionMouse.y - positionWindow.y) << std::endl;
    
    // // End

    // Game Over
    if (player -> getHealth() <= 0){
        GameOver();
    }
    if (text.bruh == 0) {
        gameConstants.isOpponent = true;
        gameConstants.isRunning = true;
    }
    }  
}

void Game::GameOver(){
    // Update best score
    enc -> add_data<int>("BestScore", max(enc -> get_item<int>("BestScore"), score));
    enc -> updatefile();
    // Paused Game
    pauseGame();
    endgame.updateFrame(0);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        unpauseGame();
        // Reset score and player's health
        player -> resetHealth();
        score = 0;
        // Reset spawn rate
        gameConstants.opponentRate = gameConstants.opponentRateOrigin;
        gameConstants.staticOpponentRate = gameConstants.staticOpponentRateOrigin;
        gameConstants.spearRate = gameConstants.spearRateOrigin;
    }
}

void Game::createOpponent(){
    Opponent* opp = new Opponent(player);
    opp -> setWindow(window);
    opp -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    opponent.push_back(opp);
}

void Game::removeOpponent(int id){
    if (opponent.size() > id){
        // Add 1 point if the opponent was killed by player
        if (opponent[id] -> getHealth() == 0) score++;
        
        delete opponent[id];
        opponent[id] = opponent[opponent.size() - 1];
        opponent.pop_back();
    }
}

void Game::createBird(){
    Birds* bird = new Birds();
    bird -> setWindow(window);
    bird -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    bird -> change_volume_bird(gameConstants.birdsVolume * gameConstants.masterVolume);
    birds.push_back(bird);
}

void Game::removeBird(int id){
    if (birds.size() > id){
        delete birds[id];
        birds[id] = birds[birds.size() - 1];
        birds.pop_back();
    }
}

void Game::createBalloon(){
    Balloon* balloon = new Balloon();
    balloon -> setWindow(window);
    balloon -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    balloons.push_back(balloon);
}

void Game::removeBalloon(int id){
    if (balloons.size() > id){
        delete balloons[id];
        balloons[id] = balloons[balloons.size() - 1];
        balloons.pop_back();
    }
}

void Game::createFireworks(){
    Fireworks* firework = new Fireworks();
    firework -> setWindow(window);
    firework -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    firework -> change_volume_fireworks(gameConstants.fireworksVolume * gameConstants.masterVolume);
    fireworks.push_back(firework);
}

void Game::removeFireworks(int id){
    if (fireworks.size() > id){
        delete fireworks[id];
        fireworks[id] = fireworks[fireworks.size() -1];
        fireworks.pop_back();
    }
}

void Game::toggleBalloons(){
    gameConstants.isBalloon = !gameConstants.isBalloon;
    enc -> add_data<int>("isBalloon", gameConstants.isBalloon ? 1 : 0);
    enc -> updatefile();
}

void Game::toggleBirds(){
    gameConstants.isBirds = !gameConstants.isBirds;
    enc -> add_data<int>("isBirds", gameConstants.isBirds ? 1 : 0);
    enc -> updatefile();
}

void Game::toggleBlackhole(){
    gameConstants.isBlackhole = !gameConstants.isBlackhole;
    enc -> add_data<int>("isBlackhole", gameConstants.isBlackhole ? 1 : 0);
    enc -> updatefile();
}

void Game::toggleFireworks(){
    gameConstants.isFireworks = !gameConstants.isFireworks;
    enc -> add_data<int>("isFireworks", gameConstants.isFireworks ? 1 : 0);
    enc -> updatefile();
}

void Game::toggleLightning(){
    gameConstants.isLightning = !gameConstants.isLightning;
    enc -> add_data<int>("isLightning", gameConstants.isLightning ? 1 : 0);
    enc -> updatefile();
}

void Game::toggleRain(){
    gameConstants.isRaining = !gameConstants.isRaining;
    enc -> add_data<int>("isRaining", gameConstants.isRaining ? 1 : 0);
    enc -> updatefile();

    if (gameConstants.isRaining) gameRain.playAudio(); else gameRain.stopAudio();
}

bool Game::getIsBalloons(){
    return gameConstants.isBalloon;
}

bool Game::getIsBirds(){
    return gameConstants.isBirds;
}

bool Game::getIsBlackhole(){
    return gameConstants.isBlackhole;
}

bool Game::getIsFireworks(){
    return gameConstants.isFireworks;
}

bool Game::getIsLightning(){
    return gameConstants.isLightning;
}

bool Game::getIsRaining(){
    return gameConstants.isRaining;
}

void Game::setBalloonsRate(float rate){
    gameConstants.balloonRate = rate;
}

void Game::setBirdsRate(float rate){
    gameConstants.birdRate = rate;
}

void Game::setFireworksRate(float rate){
    gameConstants.fireworkRate = rate;
}

void Game::setLightningRate(float rate){
    gameLightning.setLightningRate(rate);
}

float Game::getBalloonsRate(){
    return gameConstants.balloonRate;
}

float Game::getBirdsRate(){
    return gameConstants.birdRate;
}

float Game::getFireworksRate(){
    return gameConstants.fireworkRate;
}

float Game::getLightningRate(){
    return gameLightning.getLightningRate();
}

float Game::getMasterVolume(){
    return gameConstants.masterVolume;
}

float Game::getBackgroundVolume(){
    return gameConstants.backgroundVolume;
}

float Game::getRainVolume(){
    return gameConstants.rainVolume;
}

float Game::getThunderVolume(){
    return gameConstants.thunderVolume;
}

float Game::getBirdsVolume(){
    return gameConstants.birdsVolume;
}

float Game::getFireworksVolume(){
    return gameConstants.fireworksVolume;
}

void Game::setMasterVolume(float volume){
    gameConstants.masterVolume = volume;
    enc -> add_data<float>("masterVolume", volume);
    enc -> updatefile();

    setRainVolume(gameConstants.rainVolume);
    setThunderVolume(gameConstants.thunderVolume);
    setBirdsVolume(gameConstants.birdsVolume);
    setFireworksVolume(gameConstants.fireworksVolume);
    setBackgroundVolume(gameConstants.backgroundVolume);
}

void Game::setBackgroundVolume(float volume){
    gameConstants.backgroundVolume = volume;
    enc -> add_data<float>("backgroundVolume", volume);
    enc -> updatefile();

    gameBackground.changeBackgroundVolume(volume * gameConstants.masterVolume);
}

void Game::setRainVolume(float volume){
    gameConstants.rainVolume = volume;
    enc -> add_data<float>("rainVolume", volume);
    enc -> updatefile();

    gameRain.change_volume_rain(volume * gameConstants.masterVolume);
}

void Game::setThunderVolume(float volume){
    gameConstants.thunderVolume = volume;
    enc -> add_data<float>("thunderVolume", volume);
    enc -> updatefile();

    gameLightning.change_volume_lightning(volume * gameConstants.masterVolume);
}

void Game::setBirdsVolume(float volume){
    gameConstants.birdsVolume = volume;
    enc -> add_data<float>("birdsVolume", volume);
    enc -> updatefile();

    for (int i = 0; i < birds.size(); i++) 
        birds[i] -> change_volume_bird(volume * gameConstants.masterVolume);
}

void Game::setFireworksVolume(float volume){
    gameConstants.fireworksVolume = volume;
    enc -> add_data<float>("fireworksVolume", volume);
    enc -> updatefile();

    for (int i = 0; i < fireworks.size(); i++)
        fireworks[i] -> change_volume_fireworks(volume * gameConstants.masterVolume);
}

void Game::changeBackgroundPicture(int chosen){
    gameBackground.changeBackground(chosen);
    enc -> add_data<int>("background", chosen);
    enc -> updatefile();
}

void Game::setWindowSize(int width, int height){
    sf::View* view = new sf::View(sf::FloatRect(window -> getView().getViewport().left, window -> getView().getViewport().top, width, height));
    window -> setView(*view);

    gameConstants.WINDOW_WIDTH = width;
    gameConstants.WINDOW_HEIGHT = height;

    enc -> add_data<int>("WINDOW_WIDTH", width);
    enc -> add_data<int>("WINDOW_HEIGHT", height);
    enc -> updatefile();

    // Update all classes
    gameBackground.setSize(width, height);
    gameLightning.setSize(width, height);
    gameRain.setSize(width, height);
    gameWater.setSize(width, height);
    for (int i = 0; i < birds.size(); i++) 
        birds[i] -> setSize(width, height);
    for (int i = 0; i < fireworks.size(); i++)
        fireworks[i] -> setSize(width, height);
    for (int i = 0; i < balloons.size(); i++)
        balloons[i] -> setSize(width, height);

    gameSetting.setSize(width, height);

    player -> setSize(width, height);
    for (int i = 0; i < opponent.size(); i++)
        opponent[i] -> setSize(width, height);

    text.setWindowSize(width, height);
    
    // Add Spear and StaticOpponent
}

void Game::pauseGame(){
    if (!isGamePaused){
        isGamePaused = true;
        gameBackground.changeBackgroundVolume(0);
        gameRain.change_volume_rain(0);
        gameLightning.change_volume_lightning(0);
        for (int i = 0; i < birds.size(); i++) 
            birds[i] -> change_volume_bird(0);
        for (int i = 0; i < fireworks.size(); i++)
            fireworks[i] -> change_volume_fireworks(0);
    }
}

void Game::unpauseGame(){
    if (isGamePaused){
        isGamePaused = false;
        setMasterVolume(gameConstants.masterVolume);
    }
}

bool Game::getIsGamePaused(){
    return isGamePaused;
}
