#include <string>

class GroundConstants {
public:
	std::string filename[2];
	int filenamelen = 2;

	GroundConstants() {
		for (int i = 0; i < 2; i++){
			filename[i] = "ground" + std::to_string(i+1) + ".png";
		}
	}
};
