//this is a temporary test file for the arrow class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include <string>

#include "arrow.hpp"


int main(){

    Arrow arrow1 = Arrow(0.0,0.0,0.0,0.0,0.0,0.0,10.0,20.0, 20.0, "arrow.png");

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
            
            //if(event.type == sf::Event::MouseButtonPressed){
                //arrow1.shoot(10.0);
            //}
        }

        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
        window.draw(arrow1);

        // end the current frame
        window.display();
    }


    return 0;
}