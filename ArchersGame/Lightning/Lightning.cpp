#include "Lightning.hpp"

Lightning::Lightning(){
    srand(time(NULL));
    for (int i = 0; i < lightningConstants.filename_length; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Lightning/Assets/" + lightningConstants.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        lightningSprites.push_back(*sprite);
    }
    soundBuffer.loadFromFile(lightningConstants.sound_filename);
    sound.setBuffer(soundBuffer);
}

void Lightning::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Lightning::setSize(int width, int height){
    lightningWidth = width;
    lightningHeight = height;
}

void Lightning::updateFrame(double time) {
    if (timer > 0 && timer <= time){
        sound.play();
    }
    timer = std::max(0.0, timer - time);
    //std::cout << "Yo i was here" << std::endl;
    // Draw lightning at a rate
    if (((float) rand() / RAND_MAX) * lightningConstants.lightning_rate < time) {
        // Choose a random lightning
        id = rand() % lightningConstants.filename_length;
        // Set random x position
        lightningSprites[id].setPosition(rand() % lightningWidth - lightningSprites[id].getGlobalBounds().width / 2, 0.f);
        timer += lightningConstants.time;
    }
    if (timer > lightningConstants.lightning_time) window -> draw(lightningSprites[id]);
}

void Lightning::change_volume_lightning(float volume){
    sound.setVolume(volume);
}
int Lightning::getLightningRate(){
    return lightningConstants.lightning_rate;
}

void Lightning::setLightningRate(int rate){
    lightningConstants.lightning_rate = rate;
}
