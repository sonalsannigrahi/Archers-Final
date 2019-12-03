#include<string>

class LightningConstants{
    public:
    std::string filename[5];
    int filename_length = 5;
    int lightning_rate = 1000;
    double time = 0.4;
    
    LightningConstants(){
        for (int i = 0; i < filename_length; i++) filename[i] = std::to_string(i) + ".png";
    }
};
