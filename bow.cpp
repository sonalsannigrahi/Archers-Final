#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>


int main()
{
    sf::Texture playerTexture;
    playerTexture.loadFromFile("polygon.png");

    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);

    playerSprite.setOrigin(50,50);
    playerSprite.setPosition(400,300);
    playerSprite.setRotation(0);

    sf::Vector2i mouse;
    float angle;
    sf::Vector2f playerPosition;
    double x, y;

    sf::RenderWindow window(sf::VideoMode(800, 600), "you can see me!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        playerPosition = playerSprite.getPosition();
        x = mouse.x - playerPosition.x;
        y = mouse.y - playerPosition.y;

        mouse = sf::Mouse::getPosition(window);
        angle = -atan2( x , y) * 180 / 3.14;
        playerSprite.setRotation(angle);
        window.clear(sf::Color::White);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}
