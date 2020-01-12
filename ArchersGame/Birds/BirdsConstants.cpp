//
//  BirdsConstants.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 25/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include <string>

class BirdsConstants {
public:
    double changetime = 0.1;
    std::string filename[20];
    int filenamelen = 20;
    int birdlen = 10;
    int birdTypeCount = 2;
    float birdSpeed = 100.f;
    float skylimit = 0.7;
    std::string musicfile = "bird.ogg";
    
    BirdsConstants(){
        for (int i=0; i< 20; i++) {
            filename[i] = "bird" + std::to_string(i+1) + ".png";
        }
    }
};
