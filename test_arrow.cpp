//this is a temporary test file for the arrow class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

int main(){
    sf::RectangleShape body(sf::Vector2f(100, 5));
    body.setPosition(0,0);
    sf::CircleShape head(25, 3);
    head.setPosition(100, 0);
    head.rotate(60);

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

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(body);
        window.draw(head);

        // end the current frame
        window.display();
    }


    return 0;
}