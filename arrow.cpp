#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>

#include "arrow.hpp"

Arrow::Arrow(){
    this->xpos = 0;
    this->ypos = 0;
    this->angle = 0;
}

Arrow::Arrow(float x, float y, float theta = 0){
    this->xpos = x;
    this->ypos = y;
    this->angle = theta;
}