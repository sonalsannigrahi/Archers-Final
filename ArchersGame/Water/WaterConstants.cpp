//
//  WaterConstant.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 24/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//
#include <string>

class WaterConstants {
public:
    double changetimewater = 0.07;
    std::string filename[63];
    int filename_len = 63;
    float heightScale = 0.3;

    WaterConstants(){
        for (int i =1;i <= 63;i++){
            filename[i-1] = "waterAnimation" + std::to_string(i) + ".png";
        }

    }
};
