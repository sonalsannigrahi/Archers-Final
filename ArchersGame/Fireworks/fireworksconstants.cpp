#include <string>

class WaterConstants {
public:
    double changetimewater = 0.02;
    std::string filename[63];
    int filename_len = 63;

    WaterConstants(){
        for (int i =1;i <= 63;i++){
            filename[i-1] = "waterAnimation" + std::to_string(i) + ".png";
        }

    }
};
