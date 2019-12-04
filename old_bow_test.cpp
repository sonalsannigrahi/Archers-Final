#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include <Texture.hpp>

int main()
{
    sf::Texture playerTexture;
    playerTexture.loadFromFile("polygon.png");

    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        playerSprite.setOrigin(50,50);
        playerSprite.setPosition(400,300);
        playerSprite.setRotation(0);

        sf::Vector2i mouse;
        float angle;
        sf::Vector2f playerPosition;
        double a, b;

        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            playerPosition = playerSprite.getPosition();
            a = mouse.x - playerPosition.x;
            b = mouse.y - playerPosition.y;

            mouse = sf::Mouse::getPosition(window);
            angle = -atan2( a , b) * 180 / 3.14;
            playerSprite.setRotation(angle);
            window.clear(sf::Color::White);
            window.draw(playerSprite);
            window.display();
        }
    }

    return 0;
}
