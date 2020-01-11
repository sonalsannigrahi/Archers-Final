
#include <string>

class SpearConstants {
public:
    double changetime = 0.1;
    std::string filename[20];
    int filenamelen = 20;
    int spearlen = 10;
    float spearSpeed = 200.f;
    float maxHealth = 100.f;


    SpearConstants(){
        for (int i=0; i< 20; i++) {
            filename[i] = "spear" + std::to_string(i+1) + ".png";
        }
    }
};
