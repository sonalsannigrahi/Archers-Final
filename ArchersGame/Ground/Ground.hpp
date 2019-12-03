#pragma once
#include <SFML/Graphics.hpp>

#include "GroundConstants.cpp"

class Ground {
private:
		GroundConstants groundconstant = GroundConstants();
		sf::RenderWindow* window;

public:
		Ground();
};
