#include <string>

class FireworksConstants {
public:
    double changetimefireworks = 0.02;
    std::string filename[45];
    int filename_len = 45;

    FireworksConstants(){
        for (int i =1;i <= filename_len;i++){
            filename[i-1] = "frame_apngframe" + std::to_string(i) + ".png";
        }

    }
};
