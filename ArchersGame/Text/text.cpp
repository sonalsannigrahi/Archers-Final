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
    BestScore.setFont(font);
    quit.setFont(font);
    tutorial.setFont(font);
    ChooseUserName.setFont(font);
    PressEnter.setFont(font);
        

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
    bruh = -1;
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
    if(bruh == -2){

    }
    if(bruh == -1){
        Titlesprite.setPosition( (float) 450 / 900 * windowWidth - Titlesprite.getGlobalBounds().width / 2, (float) windowHeight - (float) 550 / 600 * windowHeight);
        Titlesprite.setScale(textconstants.xtitlescale, textconstants.ytitlescale);
        window -> draw(Titlesprite);
        ChooseUserName.setString("Choose an user name");
        ChooseUserName.setCharacterSize(30);
        ChooseUserName.setPosition(windowWidth/2-22*7.5,5*windowHeight/16);       
        window->draw(ChooseUserName);
        PressEnter.setString("Press Enter to Play");
        PressEnter.setCharacterSize(25);
        PressEnter.setPosition(windowWidth/2-22*5.0,5*windowHeight/10);
        if (counter > 5.0) {
            window->draw(PressEnter);
        }
    }
    else{
    if (bruh==1 ){
        Titlesprite.setPosition( (float) 450 / 900 * windowWidth - Titlesprite.getGlobalBounds().width / 2, (float) windowHeight - (float) 550 / 600 * windowHeight);
        Titlesprite.setScale(textconstants.xtitlescale, textconstants.ytitlescale);
        window -> draw(Titlesprite);
    }
    

    if (textconstants.isStartbutton){
        window -> draw(startbutton);
        startbutton.setPosition((float) 470 / 900 * windowWidth, (float) windowHeight - (float) 340 / 600 * windowHeight);
        Startsprite.setPosition((float) 465 / 900 * windowWidth, (float) windowHeight - (float) 345 / 600 * windowHeight);
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

        quit.setString("Quit");
        quit.setCharacterSize(30);
        quit.setPosition(windowWidth/2-30,5*windowHeight/16 + 90);

        BestScore.setString("Best Score");
        BestScore.setCharacterSize(30);
        BestScore.setPosition(windowWidth/2-75,5*windowHeight/16 + 60);

        textconstants.condition0 = false;

        window -> draw(play);
        window -> draw(tutorial);
        window -> draw(quit);
        window -> draw(BestScore);
        
        a = mousePosition.x; 
        b = mousePosition.y; 
        
        //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        //std::cout<< bruh << '('<<play.getPosition().x<< ','<<play.getPosition().y <<')'<<std::endl;
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
        if (a >=windowWidth/2-30 && a<=windowWidth/2+30  && b>=5*windowHeight/16 + 97 && b<=5*windowHeight/16+118){
            quit.setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                bruh = 3;
                textconstants.conditionplay = false;
            }    //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        }
        else{
            quit.setColor(sf::Color::White);
        }
        if (a >=windowWidth/2-75 && a<=windowWidth/2+75  && b>=5*windowHeight/16 + 67 && b<=5*windowHeight/16+88){
            BestScore.setColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                bruh = 4;
                textconstants.conditionplay = false;
            }    //std::cout<< bruh << '('<<a<< ','<<b <<')'<<" I was here"<<std::endl;
        }
        else{
            BestScore.setColor(sf::Color::White);
        }

    }
    if (bruh==2)
    {

    if (textconstants.condition0)
    {
        setstring(textconstants.txt0);
        setposition((float) 500 / 900 * windowWidth, (float) windowHeight - (float) 200 / 600 * windowHeight);
        textconstants.condition0 = false;
        counter = 0;
    }
    if (counter > 5 && counter < 7 && !(textconstants.is_box) && !(textconstants.hits == 5))
    {
        textconstants.condition1 = true;
    }
    if (textconstants.condition1)
    {
        setstring(textconstants.txt1);
        setposition((float) 75 / 900 * windowWidth, (float) windowHeight - (float) 300 / 600 * windowHeight);
        textconstants.condition1 = false;
    }

    if (counter > 10 && counter < 12 && !(textconstants.is_box)&& !(textconstants.hits == 5))
    {
        textconstants.condition2 = true;
    }


    if (textconstants.condition2)
    {
        setstring(textconstants.txt2);
        setposition((float) 200 / 900 * windowWidth, (float) windowHeight - (float) 450 / 600 * windowHeight);

        int xbox = rand() % (windowWidth / 3) + (windowWidth / 3);
        int ybox = rand() % (windowHeight / 3) + windowHeight - (windowHeight / 2);
        
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
        setposition((float) 300 / 900 * windowWidth, (float) windowHeight - (float) 350 / 600 * windowHeight);
        text.setColor(sf::Color::Red);
        if(textconstants.is_box){
            counter = 0;
        }
        textconstants.is_box = false;
    }
    if(counter>3 && textconstants.hits == 5){
        bruh =1;
        textconstants.conditionplay = true;
    }




    // if (counter>20){
    //     textconstants.condition4 = true;
    // }

    // if (textconstants.condition8){
    //     setstring(textconstants.txt8);
    //     setposition((float) 100 / 900 * windowWidth, (float) windowHeight - (float) 300 / 600 * windowHeight);
    //     textconstants.condition8 = false;

    // }

    // if (textconstants.condition4){
    //     setstring(textconstants.txt4);
    //     setposition((float) 500 / 900 * windowWidth, (float) windowHeight - (float) 300 / 600 * windowHeight);
    //     textconstants.condition4 = false;

    // }
    if (textconstants.is_box)
    {
        window -> draw(box);
    }

    window -> draw(text);
    
    }
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
//bruh is 0 in playing mode, 1 on startscreen, 2 on tutorial