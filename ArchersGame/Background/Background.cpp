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
    if (!texture.loadFromFile("/Users/sunho/Documents/Bachelor 2/CSE201/Archers/ArchersGame/Background/Asset/cache_4103024296.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    window -> draw(sprite);
}
