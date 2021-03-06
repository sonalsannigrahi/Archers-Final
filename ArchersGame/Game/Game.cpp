#include "Game.hpp"


sf::RenderWindow* Game::getWindow()
{
    return this->window;
}

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
    gameBackground.changeBackgroundVolume(gameConstants.backgroundVolume * gameConstants.masterVolume / 100);
    gameRain.change_volume_rain(gameConstants.rainVolume * gameConstants.masterVolume / 100);
    gameLightning.change_volume_lightning(gameConstants.thunderVolume * gameConstants.masterVolume / 100);

    // Set background
    changeBackgroundPicture(enc -> get_item<int>("background"));

    // Start rain audio
    if (gameConstants.isRaining) gameRain.playAudio();
    
    //loading font for texts
    if (!font.loadFromFile(gameConstants.filename))
    {
        std::cout << "Error text file" << std::endl;
    }
    //Settings for the score
    ScoreView.setFont(font);
    ScoreView.setPosition((float) gameConstants.WINDOW_WIDTH / 40, (float) gameConstants.WINDOW_HEIGHT / 80);
    ScoreView.setCharacterSize(50);
    ScoreView.setFillColor(sf::Color::Black);

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
            if (event.type == sf::Event::Closed || text.bruh == 3)
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
    //std::cout<<gameConstants.BestPlayer<<"\n";
    if(!gameConstants.isRunning){
        gameConstants.isOpponent = false;
    }

    // Calculate time has passed since the last UpdateFrame
    double time = 0;
    if (!isGamePaused) time = double(clock() - elapsedTime) / CLOCKS_PER_SEC;
    elapsedTime = clock();

    // Check if the screen resolution has changed
    sf::Vector2u resolution = window -> getSize();
    //std::cout << resolution.x << ' ' << resolution.y << '\n';
    if (window -> getSize().x != gameConstants.WINDOW_WIDTH || window -> getSize().y != gameConstants.WINDOW_HEIGHT)
        setWindowSize(resolution.x, resolution.y);

    //cout<<text.bruh<<endl;
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
    
    //Creating Static 
    if (((float) rand() / RAND_MAX) * gameConstants.staticOpponentRate < time && gameConstants.isStatic) 
        createStaticOpponent();
    //Creating Opponent
    if (((float) rand() / RAND_MAX) * gameConstants.opponentRate < time && gameConstants.isOpponent) 
        createOpponent();

    //Creating Spear Opponent
    if (((float) rand() / RAND_MAX) * gameConstants.spearRate < time && gameConstants.isSpear) 
        createSpear();
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

    //Draw Static Opp
    if (staticOpponent.size() > 0){
        int id = 0;
        while (id < staticOpponent.size()){
            if (staticOpponent[id] -> isAlive()){
                staticOpponent[id] -> updateFrame(time);
                id++;
            }
            else removeStaticOpponent(id);
        }
    }

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
    //Draw Spear
    if (spear.size()>0){
        int id=0;
        while(id<spear.size()){
            if(spear[id] -> isAlive()){
                spear[id] -> updateFrame(time);
                id++;
            }
            else removeSpear(id);
        }
    }
    
    //Show Score
    if(text.bruh ==0) {
        ScoreView.setString(std::to_string(score));
        window->draw(ScoreView);
    }

    // Draw Arrow (test)
    // arrow.updateFrame(time);

    // Draw Water
    gameWater.updateFrame(time);

    // Draw Setting
    if (player -> getHealth() > 0) gameSetting.updateFrame(time);
    
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
        gameConstants.isSpear = true;
        gameConstants.isStatic = true;
        gameConstants.isRunning = true;
    }
    if(text.bruh == 4){
        gameConstants.isOpponent = false;
        gameConstants.isSpear = false;
        gameConstants.isStatic = false;
        gameConstants.isRunning = false;
        text.updateFrame(time);
        sf::Text best_pont =  sf::Text( std::to_string(gameConstants.BestScore), text.font, 50);
        sf::String s = to_string(gameConstants.BestScore);
        int n = s.getSize();
        best_pont.setPosition(gameConstants.WINDOW_WIDTH/2 - (n)*(3)*(7,5), 5*gameConstants.WINDOW_HEIGHT/16);
        best_pont.setFillColor(sf::Color::White);
        window->draw(best_pont);
        sf::String sentence =  "by " + gameConstants.BestPlayer;
        sf::Text best = sf::Text( sentence, text.font, 20);
        int lettersnumber = sentence.getSize();
        best.setPosition(gameConstants.WINDOW_WIDTH/2- lettersnumber*(7,5),5*gameConstants.WINDOW_HEIGHT/16 + 80);
        window->draw(best);
       
    }
    }
}

void Game::GameOver(){
    // Update best score
    //std::cout<<score<<endl;
    //std::cout<<gameConstants.BestScore<<std::endl;
    //std::cout<<gameConstants.BestPlayer<<std::endl;
    enc -> add_data<int>("BestScore", max(gameConstants.BestScore, score));
    if(max(gameConstants.BestScore, score) > gameConstants.BestScore){
         enc -> add_data_string("BestPlayer", UserName);
    }
    //std::cout<<enc->get_item_string("BestPlayer")<< " got "<<enc->get_item<int>("BestScore")<<std::endl;
    enc -> updatefile();
    // Paused Game
    //pauseGame(); //Didn't pause game because settings page pops up then.
    endgame.updateFrame(0);
    sf::Vector2i windowPosition;
    sf::Vector2i mousePosition;
    mousePosition = sf::Mouse::getPosition(*window);
    //Change Score View
    ScoreView.setFillColor(sf::Color::White);
    ScoreView.setCharacterSize(70);
    ScoreView.setPosition(float(gameConstants.WINDOW_WIDTH)/2, float(gameConstants.WINDOW_HEIGHT)/2);
    window -> draw(ScoreView);
    //Stop Spwaning Characters
    gameConstants.isOpponent = false;
    gameConstants.isSpear = false;
    gameConstants.isStatic = false;
    gameConstants.isRunning = false;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //std::cout << "i am here" << std::endl;
        //std::cout << (mousePosition.x, mousePosition.y) << std::endl;
        if (endgame.replay -> getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
            //std::cout << "i clicked exit" << std::endl;
            //unpauseGame();
            // Reset score, score position, and player's health
            ScoreView.setPosition(float(gameConstants.WINDOW_WIDTH)/40, float(gameConstants.WINDOW_HEIGHT)/80);
            ScoreView.setFillColor(sf::Color::Black);
            ScoreView.setCharacterSize(50);
            player -> resetHealth();
            score = 0;
            //ScoreView.setPosition((float) gameConstants.WINDOW_WIDTH / 40, (float) gameConstants.WINDOW_HEIGHT / 80);
            // Remove all opponents
            while (opponent.size() > 0) removeOpponent(0);
            while (spear.size() > 0) removeSpear(0);
            while (staticOpponent.size() > 0) removeStaticOpponent(0);
            // Reset spawn rate
            gameConstants.opponentRate = gameConstants.opponentRateOrigin;
            gameConstants.staticOpponentRate = gameConstants.staticOpponentRateOrigin;
            gameConstants.spearRate = gameConstants.spearRateOrigin;
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //std::cout << "i am here" << std::endl;
        //std::cout << endgame.exit -> getGlobalBounds() << std::endl;
        //std::cout << (mousePosition.x, mousePosition.y) << std::endl;
        if(endgame.exit -> getGlobalBounds().contains(mousePosition.x,mousePosition.y)){
            //std::cout << "i clicked exit" << std::endl;
            //unpauseGame();
            // Reset score and player's health
            ScoreView.setPosition(float(gameConstants.WINDOW_WIDTH)/40, float(gameConstants.WINDOW_HEIGHT)/80);
            ScoreView.setFillColor(sf::Color::Black);
            ScoreView.setCharacterSize(50);
            player -> resetHealth();
            score = 0;
            //ScoreView.setPosition((float) gameConstants.WINDOW_WIDTH / 40, (float) gameConstants.WINDOW_HEIGHT / 80);
            // Remove all opponents
            while (opponent.size() > 0) removeOpponent(0);
            while (spear.size() > 0) removeSpear(0);
            while (staticOpponent.size() > 0) removeStaticOpponent(0);
            // Reset spawn rate
            gameConstants.opponentRate = gameConstants.opponentRateOrigin;
            gameConstants.staticOpponentRate = gameConstants.staticOpponentRateOrigin;
            gameConstants.spearRate = gameConstants.spearRateOrigin;
            text.bruh = 1;
            text.textconstants.conditionplay = true;
            text.textconstants.condition0 = false;
            text.textconstants.condition1 = false;
            text.textconstants.condition2 = false;
            text.textconstants.condition3 = false;
            text.textconstants.condition4 = false;
        }
    }

}

void Game::createStaticOpponent(){
    StaticOpponent* sta = new StaticOpponent(player, &text);
    sta -> setWindow(window);
    sta -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    staticOpponent.push_back(sta);
}

void Game::removeStaticOpponent(int id){
    if (staticOpponent.size() > id){
        // Add 1 point if the opponent was killed by player
        if (staticOpponent[id] -> getHealth() <= 0) score++;
        
        delete staticOpponent[id];
        staticOpponent[id] = staticOpponent[staticOpponent.size() -1];
        staticOpponent.pop_back();
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
        if (opponent[id] -> getHealth() <= 0) score++;
        
        delete opponent[id];
        opponent[id] = opponent[opponent.size() - 1];
        opponent.pop_back();
    }
}

void Game::createSpear(){
    Spear* sp = new Spear(player, &text);
    sp -> setWindow(window);
    sp -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    spear.push_back(sp);
}

void Game::removeSpear(int id){
    if (spear.size() > id){
        // Add 1 point if the opponent was killed by player
        if (spear[id] -> getHealth() <= 0) score++;
        
        delete spear[id];
        spear[id] = spear[spear.size() - 1];
        spear.pop_back();
    }
}
void Game::createBird(){
    Birds* bird = new Birds();
    bird -> setWindow(window);
    bird -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    bird -> change_volume_bird(gameConstants.birdsVolume * gameConstants.masterVolume / 100);
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
    firework -> change_volume_fireworks(gameConstants.fireworksVolume * gameConstants.masterVolume / 100);
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

    gameBackground.changeBackgroundVolume(volume * gameConstants.masterVolume / 100);
}

void Game::setRainVolume(float volume){
    gameConstants.rainVolume = volume;
    enc -> add_data<float>("rainVolume", volume);
    enc -> updatefile();

    gameRain.change_volume_rain(volume * gameConstants.masterVolume / 100);
}

void Game::setThunderVolume(float volume){
    gameConstants.thunderVolume = volume;
    enc -> add_data<float>("thunderVolume", volume);
    enc -> updatefile();

    gameLightning.change_volume_lightning(volume * gameConstants.masterVolume / 100);
}

void Game::setBirdsVolume(float volume){
    gameConstants.birdsVolume = volume;
    enc -> add_data<float>("birdsVolume", volume);
    enc -> updatefile();

    for (int i = 0; i < birds.size(); i++)
        birds[i] -> change_volume_bird(volume * gameConstants.masterVolume / 100);
}

void Game::setFireworksVolume(float volume){
    gameConstants.fireworksVolume = volume;
    enc -> add_data<float>("fireworksVolume", volume);
    enc -> updatefile();

    for (int i = 0; i < fireworks.size(); i++)
        fireworks[i] -> change_volume_fireworks(volume * gameConstants.masterVolume / 100);
}

void Game::changeBackgroundPicture(int chosen){
    gameBackground.changeBackground(chosen);
    enc -> add_data<int>("background", chosen);
    enc -> updatefile();
}

void Game::setWindowSize(int width, int height){
    window -> setSize(sf::Vector2u(width, height));
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
    for (int i = 0; i < spear.size(); i++)
        spear[i] -> setSize(width, height);
    for (int i = 0; i < staticOpponent.size(); i++)
        staticOpponent[i] -> setSize(width, height);

    text.setWindowSize(width, height);
    ScoreView.setPosition(float(width)/40,float(height)/80);
}

void Game::pauseGame(){
    if (!isGamePaused){
        text.textconstants.isSettingOpen = true;
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
        text.textconstants.isSettingOpen = false;
        isGamePaused = false;
        setMasterVolume(gameConstants.masterVolume);
    }
}

bool Game::getIsGamePaused(){
    return isGamePaused;
}
