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
    double changetime = 0.05;
    std::string filename[20];
    int filenamelen = 20;
    
    BirdsConstants(){
        for (int i=0; i< 20; i++) {
            filename[i] = "bird" + std::to_string(i+1) + ".png";
            
        }
    }
};
