#include "text.hpp"

Texts::Texts(){
    if (!font.loadFromFile(textconstants.filename))
    {
        std::cout << "Error text file" << std::endl;
    }

    text.setFont(font);
    setsize(textconstants.size);

    

    //Button stuff

    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile(textconstants.wood_filename);

    button.setSize(sf::Vector2f(250, 75));
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(1);
    button.setPosition(600,windowHeight+100);
    button.setTexture(texture);

    text_button.setPosition(button.getPosition());
    text_button.setString(textconstants.txt_button);
    text_button.setFont(font);
    text_button.setCharacterSize(42);

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
    if (textconstants.isbutton){
        window -> draw(button);
        window -> draw(text_button);
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
    if (button.getPosition().x <= x && x <= button.getPosition().x + button.getSize().x &&
        button.getPosition().y <= y && y <= button.getPosition().y + button.getSize().y){
            bruh = 0;
            textconstants.isbutton = false;
            return true;
}
}
//bruh