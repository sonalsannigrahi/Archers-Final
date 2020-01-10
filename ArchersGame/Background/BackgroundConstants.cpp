//
//  BackgroundConstants.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 22/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include <string>

class BackgroundConstants{
public:
    int filename_length = 10;
    int chosen = 7;
    std::string filename[10];
    std::string musicfile = "DarkWinds.ogg";

    BackgroundConstants(){
        for (int i = 1; i <= filename_length; i++) filename[i - 1] = "background" + std::to_string(i) + ".png";
    }
};
