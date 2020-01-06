#include "Encryption.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    Encrypt enc;

    // Background
        int background = 7;
    // Window setting
        int WINDOW_HEIGHT = 600;
        int WINDOW_WIDTH = 900;
    // Game setting
        bool isRaining = true;
        bool isLightning = true;
        bool isBirds = true;
        bool isBalloon = true;
        bool isFireworks = true;
        bool isBlackhole = true;
    // Volume
        float masterVolume = 0.0;
        float rainVolume = 100.0;
        float thunderVolume = 100.0;
        float birdsVolume = 100.0;
        float fireworksVolume = 100.0;
        float backgroundVolume = 100.0;

    enc.add_data<int>("damage",100);
    enc.add_data<float>("size",100.5);
    enc.add_data<long long>("remaining_health",1031314567899);
    enc.updatefile();

    cout<<"damage = "<<enc.get_item<int>("damage")<<'\n';
    cout<<"size = "<<enc.get_item<float>("size")<<"\n";
    cout<<"remaining_health = "<<enc.get_item<long long>("remaining_health")<<'\n';
    cout<<"gay = "<<enc.get_item<int>("gay")<<'\n';
    enc.updatefile();

    return 0;
}
