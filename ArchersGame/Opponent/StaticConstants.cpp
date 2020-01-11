
#include <string>

class StaticConstants {
public:
    double changetime = 0.3;
    std::string filename[10];
    int filenamelen = 10;
    int statlen = 10;
    float statSpeed = 200.f;
    float maxHealth = 100.f;

    StaticConstants(){
        for (int i=0; i< 10; i++) {
            filename[i] = "stat.png";
        }
    }
};
