
#include <string>

class CharConstants {
public:
    double changetime = 0.15;
    std::string filename[10];
    int filenamelen = 10;
    int charlen = 10;
    float charSpeed = 200.f;
    float maxHealth = 100.f;

    CharConstants(){
        for (int i=0; i< 10; i++) {
            filename[i] = "run" + std::to_string(i+1) + ".png";
        }
    }
};
