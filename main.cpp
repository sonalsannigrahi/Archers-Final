
#include <SFML/Graphics.hpp>


int main()
{   //menu
    int menuh = 800;
    int menuw = 800;
    sf::RenderWindow window(sf::VideoMode(menuw, menuh), "ARCHERS",sf::Style::Fullscreen);
    int recth = 60;
    int rectw = 100;
    sf::RectangleShape play(sf::Vector2f(rectw,recth));
    play.setFillColor(sf::Color::Red);
    play.setOrigin(sf::Vector2f(rectw/2, recth/2));
    play.setPosition(sf::Vector2f(400,400));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed or event.type == sf::Event::KeyEvent(K)))
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(play);
        window.display();
    }

    return 0;
}
