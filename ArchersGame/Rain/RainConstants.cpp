#include<string>

class RainConstants{
public:
    int filename_length = 8;
    std::string filename[8];
    double changeTime = 0.125;
    std::string sound_filename = "Rain/Assets/rain.ogg";

    RainConstants(){
        for (int i = 0; i < filename_length; i++) filename[i] = std::to_string(i) + ".png";
    }
};
