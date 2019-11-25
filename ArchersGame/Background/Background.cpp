//
//  Background.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 22/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Background.hpp"

void Background::updateFrame(double time) {
    sf::Texture texture;
    texture.loadFromFile("Background/Asset/bgimg.jpg");
    //std::cout << "Yo i was here" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);
}
