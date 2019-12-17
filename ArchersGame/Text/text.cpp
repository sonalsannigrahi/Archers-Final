#include "text.hpp"

Texts::Texts(){
    if (!font.loadFromFile(textconstants.filename))
    {
        std::cout << "Error text file" << std::endl;
    }

    text.setFont(font);
    setsize(textconstants.size);
    setstring(textconstants.txt);
    setposition(500,500);
    
}

void Texts::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Texts::setWindowSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
}

void Texts::setstring(std::string txt){
     text.setString(txt);
}

void Texts::setsize(int px){
    text.setCharacterSize(px);
}

void Texts::setposition(float x, float y){
    text.setPosition(x,y);
}

void Texts::updateFrame(double time) {

    window -> draw(text);
    
}