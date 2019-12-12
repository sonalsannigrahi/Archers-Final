#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include <string>
#include "arrow.hpp"

Arrow::Arrow(){
    this->xpos = 0;
    this->ypos = 0;
    this->angle = 0;

    this->texture.loadFromFile("arrow.png");
    this->arrow.setTexture(texture);
    this->arrow.setScale(sf::Vector2f(0.5f, 0.5f)); //default values, real ones tbd from character interation
}

Arrow::Arrow(float x, float y, float theta = 0, std::string filename){
    this->xpos = x;
    this->ypos = y;
    this->angle = theta;

    this->texture.loadFromFile(filename);
    this->arrow.setTexture(texture);
    this->arrow.setScale(sf::Vector2f(0.5f, 0.5f));//default values, real ones tbd

    this->arrow.setRotation(this->angle);
}

void Arrow::shoot(){
    //need to implement the movement using the physics engine point mass class, Arrow to be made a subclass?
}