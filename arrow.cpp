#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

#include "arrow.hpp"

Arrow::Arrow(){
    this->xpos = 0;
    this->ypos = 0;
    this->angle = 0;
    this->body.setSize(10);
    this->body.setPosition(5, 0);
    this->head.setRadius(5);
    this->head.setPointCount(3);
    this->head.setPosition(10, 0);
}

Arrow::Arrow(float x, float y, float theta = 0){
    this->xpos = x;
    this->ypos = y;
    this->angle = theta;
    this->body.setSize(10);
    this->body.setPosition(5+this->xpos, this->ypos);
    this->body.rotate(this->angle);
    this->head.setRadius(5);
    this->head.setPointCount(3);
    this->head.setPosition(10, 0);
}