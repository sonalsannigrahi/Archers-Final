#include <string>
#include <stdlib.h> 

class TextConstants{
    public:
    std::string filename = "Text/asset/font.TTF";
    std::string Startfilename = "Text/asset/play.png";
    std::string titlefilename = "Text/asset/index.png";
    std::string boxfilename = "Text/asset/wood.jpeg";
    std::string box_sound = "Text/asset/wood_hit.ogg";
    int size = 30;

    std::string txt_button = "Start Game";


    std::string txt0 = "Welcome to the tutorial!";
    std::string txt1 = "This is you";
    std::string txt2 = "Try to hit the target across the screen";
    std::string txt3 = "Nice! Do it again!";
    std::string txt4 = "Congratulations!";
    std::string txt5 = "This is your health bar";
    //std::string txt6 = "This is a Black Hole";
    //std::string txt7 = "Arrows flying close to it will change their trajectory, be careful!";
    std::string txt8 = "Enjoy the game";
    int hits = 0;
    float xStartscale = 0.35;
    float yStartscale = 0.35;
    float xtitlescale = 0.8;
    float ytitlescale = 0.8;
    bool conditionplay = true;
    bool isStartbutton = false;
    bool is_box = false;
    bool condition0 = false;
    bool condition1 = false;
    bool condition2 = false;
    bool condition3 = false;
    bool condition4 = false;
    //bool condition8 = false;
};