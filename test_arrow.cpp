//this is a temporary test file for the arrow class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

int main(){
    sf::Texture texture;
    texture.loadFromFile("arrow.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

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
        window.draw(sprite);

        // end the current frame
        window.display();
    }


    return 0;
}