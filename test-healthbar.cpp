// this is a temporary test file for the healthbar class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

int main(){

    sf::Sprite rectangle;
    sf::Sprite filling;
    float health = 0.05;
    std::string colour;

    sf::Texture texture_rect;
    texture_rect.loadFromFile("Assets/healthbar_moving.png");
    // texture_rect.setSmooth(true);
    rectangle.setTexture(texture_rect);
    rectangle.setPosition(0.f, 0.f);
    sf::Texture texture_green;
    texture_green.loadFromFile("Assets/hb_green_rect.png");
    sf::Texture texture_orange;
    texture_orange.loadFromFile("Assets/hb_orange_rect.png");
    sf::Texture texture_red;
    texture_red.loadFromFile("Assets/hb_red_rect.png");
    if (health > 0.25) {
        filling.setTexture(texture_green);
        colour = "green";
    } else if (health > 0.10) {
        filling.setTexture(texture_orange);
        colour = "orange";
    } else {
        filling.setTexture(texture_red);
        colour = "red";
    }
    filling.setScale(health, 1.0f);
    filling.setPosition(113.f, 32.f);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), colour);

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