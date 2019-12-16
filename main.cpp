
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class TextinBox
{
    public:
        TextinBox(int x, int y, int sizex, int sizey, string str){
            sf::RectangleShape rectangle(sf::Vector2f(sizex,sizey));
            sf::Text text;
            sf::Font font;
            if (!font.loadFromFile("AbyssinicaSIL-R.ttf"))
            {
                std::cout << "no font file" << std::endl;
            }
            text.setFont(font);
            text.setString(str);
            text.setCharacterSize(50);
            text.setPosition(sf::Vector2f(x,y));
            text.setOrigin(sf::Vector2f(sizex/2, sizey/2));
            text.setFillColor(sf::Color::Blue);
            rectangle.setFillColor(sf::Color::Red);
            rectangle.setOrigin(sf::Vector2f(sizex/2, sizey/2));
            rectangle.setPosition(sf::Vector2f(x,y));
        }
};


int main()
{   //menu
    int menuh = 800;
    int menuw = 800;
    sf::RenderWindow window(sf::VideoMode(menuw, menuh), "ARCHERS",sf::Style::Fullscreen);
    int recth = 60;
    int rectw = 100;
    sf::RectangleShape play(sf::Vector2f(rectw,recth));
    sf::Text text;
    TextinBox Box1(400,400,rectw,recth,"Play Game");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(Box1.text);
        window.draw(Box1.rectangle);
        window.display();
    }

    return 0;
}
