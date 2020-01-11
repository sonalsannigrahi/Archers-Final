#include <string>

class FireworksConstants {
public:
    double changetimefireworks = 0.05;
    std::string filename[40];
    int filename_len = 40;
    float skylimit = 0.4;
    float scalex = 0.4;
    float scaley = 0.4;
    std::string sound_filename = "Fireworks/asset/firework_sound1.ogg";

    FireworksConstants(){
        for (int i =1;i <= filename_len;i++){
            filename[i-1] = "frame_apngframe" + std::to_string(i) + ".png";
        }

    }
};
