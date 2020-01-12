#include "graphics.h"
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Window", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event)) // Event handler
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
					menu.MoveLeft();
					break;

				case sf::Keyboard::Right:
					menu.MoveRight();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0: // Play button
						// What do i put here to reset my screen so i can put my actual game on the screen?
						break;
					case 1: // Exit
						window.close();
						break;
					}
					break;
				}

				break;

			case sf::Event::Closed:
				window.close();

				break;
			}
		}

		window.clear(sf::Color(135, 206, 250)); // Light blue
		menu.draw(window); // Draw the menu
		window.display(); // Display
	}

	return 0;
}
 Edit & Run
