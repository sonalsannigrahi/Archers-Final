#include "text.hpp"
#include <iostream>

Texts::Texts(){
    //loading font
    if (!font.loadFromFile(textconstants.filename))
    {
        std::cout << "Error text file" << std::endl;
    }
    // title
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile(textconstants.Startfilename);
    Startsprite = sf::Sprite(*texture);
     sf::Texture* texturetitle = new sf::Texture();
    texturetitle -> loadFromFile(textconstants.titlefilename);
    Titlesprite = sf::Sprite(*texturetitle);

    //setting font
    text.setFont(font);
    play.setFont(font);
    settings.setFont(font);
    tutorial.setFont(font);

    //setting size
    setsize(textconstants.size);
    startbutton.setSize(sf::Vector2f(60, 60));
    box.setSize(sf::Vector2f(30, 120));

    //setting color
    startbutton.setFillColor(sf::Color::Cyan);
    startbutton.setOutlineColor(sf::Color::Black);
    startbutton.setOutlineThickness(5);

    //box
    sf::Texture* texture_box = new sf::Texture();
    texture_box -> loadFromFile(textconstants.boxfilename);
    box.setTexture(texture_box);

    soundBuffer.loadFromFile(textconstants.box_sound);
    sound.setBuffer(soundBuffer);

    //dummy variable
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
    //mousePosition = sf::Mouse::getPosition();
    float a;
    float b;
    sf::Vector2i windowPosition;
    windowPosition = window -> getPosition();
    mousePosition = sf::Mouse::getPosition(*window);
    if (textconstants.conditionplay)
    {
        play.setString("Play");
        play.setCharacterSize(30);
        play.setPosition(windowWidth/2-30,5*windowHeight/16);

        tutorial.setString("Tutorial");
        tutorial.setCharacterSize(30);
        tutorial.setPosition(windowWidth/2-60,5*windowHeight/16 + 30);

        settings.setString("Settings");
        settings.setCharacterSize(30);
        settings.setPosition(windowWidth/2-60,5*windowHeight/16 + 60);

        textconstants.condition0 = false;

        window -> draw(play);
        window -> draw(tutorial);
        window -> draw(settings);
        a = mousePosition.x; 
        b = mousePosition.y; 
        
        std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        std::cout<< bruh << '('<<play.getPosition().x<< ','<<play.getPosition().y <<')'<<std::endl;
        if (a >=windowWidth/2-30 && a<=windowWidth/2+30 && b>=5*windowHeight/16 + 7 && b<=5*windowHeight/16+28){
            play.setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                bruh = 0;
                textconstants.conditionplay = false;
            }    //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        }
        else{
            play.setColor(sf::Color::White);
        }
        if (a >=windowWidth/2-60 && a<=windowWidth/2+60 && b>=5*windowHeight/16 + 37 && b<=5*windowHeight/16+58){
            tutorial.setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                bruh = 2;
                textconstants.condition0 = true;
                textconstants.conditionplay = false;
            }    //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        }
        else{
            tutorial.setColor(sf::Color::White);
        }
        if (a >=windowWidth/2-60 && a<=windowWidth/2+60 && b>=5*windowHeight/16 + 67 && b<=5*windowHeight/16+88){
            settings.setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                bruh = 3;
                textconstants.conditionplay = false;
            }    //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        }
        else{
            settings.setColor(sf::Color::White);
        }

    }
    if (bruh==2)
    {

    if (textconstants.condition0)
    {
        setstring(textconstants.txt0);
        setposition(500,windowHeight-200);
        textconstants.condition0 = false;
        counter = 0;
    }
    if (counter > 5 && counter < 7 && !(textconstants.is_box))
    {
        textconstants.condition1 = true;
    }
    if (textconstants.condition1)
    {
        setstring(textconstants.txt1);
        setposition(75,windowHeight-300);
        textconstants.condition1 = false;
    }

    if (counter > 10 && counter < 12 && !(textconstants.is_box))
    {
        textconstants.condition2 = true;
    }


    if (textconstants.condition2)
    {
        setstring(textconstants.txt2);
        setposition(200,windowHeight-450);

        int xbox = rand() % 300 + 300;
        int ybox = rand() % 200 + windowHeight-300;
        
        box.setPosition(xbox,ybox);
        box.setOutlineThickness(3);
        box.setOutlineColor(sf::Color::Black);
        textconstants.is_box = true;
        textconstants.condition2 = false;
    }

    if (textconstants.hits == 1)
    {
        setstring(textconstants.txt3);
    }

    if (textconstants.hits == 5)
    {
        setstring(textconstants.txt4);
        setposition(300,windowHeight-350);
        text.setColor(sf::Color::Red);
        textconstants.is_box = false;
    }




    // if (counter>20){
    //     textconstants.condition4 = true;
    // }

    // if (textconstants.condition8){
    //     setstring(textconstants.txt8);
    //     setposition(100,windowHeight-300);
    //     textconstants.condition8 = false;

    // }

    // if (textconstants.condition4){
    //     setstring(textconstants.txt4);
    //     setposition(500,windowHeight-300);
    //     textconstants.condition4 = false;

    // }
    if (textconstants.is_box)
    {
        window -> draw(box);
    }

    window -> draw(text);
    
    }

    
    
} 
bool Texts::box_hit(float x,float y){
if ( textconstants.is_box && box.getPosition().x <= x && x <= box.getPosition().x + box.getSize().x &&
        box.getPosition().y <= y && y <= box.getPosition().y + box.getSize().y)
        {
            //textconstants.condition3 = true;
            //textconstants.is_box = false;
            sound.play();
            textconstants.hits ++;
            textconstants.condition2 = true;
            //counter = 0;

        }
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