#include<string>

class LightningConstants{
    public:
    std::string filename[5];
    int filename_length = 5;
    float lightning_rate = 1.0;
    double time = 0.8;
    double lightning_time = 0.4;
    std::string sound_filename = "Lightning/Assets/Thunder.ogg";
    
    LightningConstants(){
        for (int i = 0; i < filename_length; i++) filename[i] = std::to_string(i) + ".png";
    }
};
