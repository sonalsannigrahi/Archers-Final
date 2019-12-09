// this is a temporary test file for the healthbar class

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

int main(){

    sf::Sprite rectangle;
    sf::Sprite filling;
    float health = 1;

    sf::Texture texture_rect;
    texture_rect.loadFromFile("Assets/healthbar_moving.png");
    // texture_rect.setSmooth(true);
    rectangle.setTexture(texture_rect);
    rectangle.setPosition(0.f, 0.f);
    sf::Texture texture_green;
    texture_green.loadFromFile("Assets/healthbar_rectangle_g.png");
    sf::Texture texture_orange;
    texture_orange.loadFromFile("Assets/healthbar_rectangle_o.png");
    sf::Texture texture_red;
    texture_red.loadFromFile("Assets/healthbar_rectangle_r.png");
    if (0.25 < health < 1) {
        filling.setTexture(texture_green);
    } else if (0.10 < health <= 0.25) {
        filling.setTexture(texture_orange);
    } else {
        filling.setTexture(texture_red);
    }
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