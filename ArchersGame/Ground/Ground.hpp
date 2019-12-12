#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <iostream>

#include "GroundConstants.cpp"

class Ground {
private:
	sf::RenderWindow* window;
	GroundConstants groundconstant = GroundConstants();
	std::vector<sf::Sprite> groundSprites;
	int groundHeight, groundWidth;

	float x, y;

public:
		Ground();

		void setWindow(sf::RenderWindow* gameWindow);
		void setSize(int width, int height);
		void updateFrame(double time);

		int createGround(int style);
		void setGroundPosition(int id, float x, float y);
		sf::Vector2f getGroundPosition(int id);
		void deleteGround(int id);
};
