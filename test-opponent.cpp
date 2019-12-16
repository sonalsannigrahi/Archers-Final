// this is a temporary test file for the healthbar class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

int main(){

    sf::Sprite opponent;

    sf::Texture texture;
    texture.loadFromFile("Assets/opponentsprite.png");
    opponent.setTexture(texture);
    opponent.setPosition(600.f, 400.f);
    opponent.setScale(0.35, 0.35);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Opponent window");

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
        window.draw(opponent);

        // end the current frame
        window.display();
    }


    return 0;
}