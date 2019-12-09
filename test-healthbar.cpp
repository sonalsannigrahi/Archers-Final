// this is a temporary test file for the healthbar class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

int main(){

    sf::Sprite rectangle;
    sf::Sprite filling;
    float health = 0.2;

    sf::Texture texture1;
    texture1.loadFromFile("Assets/healthbar_moving.png");
    rectangle.setTexture(texture1);
    rectangle.setPosition(0.f, 0.f);
    sf::Texture texture2;
    texture2.loadFromFile("Assets/healthbar_rectangle.png");
    filling.setTexture(texture2);
    filling.setScale(health, 1.0f);
    filling.setPosition(114.f, 31.f);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

 
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
        window.draw(rectangle);
        window.draw(filling);

        // end the current frame
        window.display();
    }


    return 0;
}