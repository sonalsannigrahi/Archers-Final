#include "text.hpp"
#include <iostream>

Texts::Texts(){
    if (!font.loadFromFile(textconstants.filename))
    {
        std::cout << "Error text file" << std::endl;
    }
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile(textconstants.Startfilename);
    Startsprite = sf::Sprite(*texture);
     sf::Texture* texturetitle = new sf::Texture();
    texturetitle -> loadFromFile(textconstants.titlefilename);
    Titlesprite = sf::Sprite(*texturetitle);
    text.setFont(font);
    play.setFont(font);
    settings.setFont(font);
    tutorial.setFont(font);
    setsize(textconstants.size);
    startbutton.setSize(sf::Vector2f(60, 60));
    startbutton.setFillColor(sf::Color::Cyan);
    startbutton.setOutlineColor(sf::Color::Black);
    startbutton.setOutlineThickness(5);
    bruh = 1;
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
    if (bruh==1){
        Titlesprite.setPosition( 250, windowHeight-550);
        Titlesprite.setScale(textconstants.xtitlescale, textconstants.ytitlescale);
        window -> draw(Titlesprite);
    }

    if (textconstants.isStartbutton){
        window -> draw(startbutton);
        startbutton.setPosition(470,windowHeight-340);
        Startsprite.setPosition( 465, windowHeight-345);
        Startsprite.setScale(textconstants.xStartscale, textconstants.yStartscale);
        window -> draw(Startsprite);
    }
    sf::Vector2i mousePosition;
    mousePosition = sf::Mouse::getPosition();
    float a;
    float b;
    sf::Vector2i windowPosition;
    windowPosition = window -> getPosition();
    if (textconstants.conditionplay)
    {
        play.setString("Play");
        play.setCharacterSize(30);
        play.setPosition(420,windowHeight-400);
        tutorial.setString("Tutorial");
        tutorial.setCharacterSize(30);
        tutorial.setPosition(400,windowHeight-370);
        settings.setString("Settings");
        settings.setCharacterSize(30);
        settings.setPosition(400,windowHeight-340);
        textconstants.condition0 = false;
        window -> draw(play);
        window -> draw(tutorial);
        window -> draw(settings);
        a = mousePosition.x - windowPosition.x;
        b = mousePosition.y - windowPosition.y;
        if (a >=409 && a<=476 && b>=176 && b<=192){
            play.setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                bruh = 0;
                textconstants.conditionplay = false;
            }    //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        }
        else{
            play.setColor(sf::Color::White);
        }


        counter = 0;

    }

    if (textconstants.condition0)
    {
        setstring(textconstants.txt0);
        setposition(500,windowHeight-200);
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
        textconstants.condition8 = true;
    }
    
    if (counter>20){
        textconstants.condition4 = true;
    }

    if (textconstants.condition8){
        setstring(textconstants.txt8);
        setposition(100,windowHeight-300);
        textconstants.condition8 = false;

    }

    if (textconstants.condition4){
        setstring(textconstants.txt4);
        setposition(500,windowHeight-300);
        textconstants.condition4 = false;

    }

    window -> draw(text);
    


    
    
} 
bool Texts::loadgame(float x, float y){
    if (startbutton.getPosition().x <= x && x <= startbutton.getPosition().x + startbutton.getSize().x &&
        startbutton.getPosition().y <= y && y <= startbutton.getPosition().y + startbutton.getSize().y){
            bruh = 0;
            textconstants.isStartbutton = false;
            return true;
}
}
//bruh