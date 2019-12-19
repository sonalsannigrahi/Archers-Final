#include "text.hpp"

Texts::Texts(){
    if (!font.loadFromFile(textconstants.filename))
    {
        std::cout << "Error text file" << std::endl;
    }

    text.setFont(font);
    setsize(textconstants.size);
    
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
    counter += time;

    if (textconstants.condition0)
    {
        setstring(textconstants.txt0);
        setposition(400,windowHeight-200);
        textconstants.condition0 = false;
        counter = 0;
    }
    
    if (textconstants.condition1){
        setstring(textconstants.txt1);
        textconstants.condition1 = false;
        counter = 0;
    }
    if (textconstants.condition2){
        setstring(textconstants.txt2);
        textconstants.condition2 = false;
        counter = 0;
    }
    if (textconstants.condition3){
        setstring(textconstants.txt3);
        setposition(20,40);
        textconstants.condition3 = false;
        counter = 0;
    }
    if (counter > 10){
        textconstants.condition4 = true;
    }

    if (textconstants.condition4){
        setstring(textconstants.txt4);
        setposition(400,windowHeight-200);
        textconstants.condition4 = false;

    }

    window -> draw(text);


    
    
}