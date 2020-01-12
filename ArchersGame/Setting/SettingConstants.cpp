#include<string>

class SettingConstants{
public:
    std::string settingButtonImage = "settingbutton.png";
    float scale = 0.2;
    std::string fontfile = "Setting/Asset/font.TTF";
    std::string robotofile = "Setting/Asset/Roboto-Regular.ttf";
    std::string filename[10];
    int filename_length = 10;

    SettingConstants(){
        for (int i = 1; i <= filename_length; i++) filename[i - 1] = "Background/Asset/background" + std::to_string(i) + ".png";
    }
};