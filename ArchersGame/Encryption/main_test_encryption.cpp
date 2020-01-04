#include "Encryption.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    Encrypt enc;

    // ADD DATA

    // Window setting
        // int WINDOW_HEIGHT = 600;
        // int WINDOW_WIDTH = 900;
    enc.add_data<int>("WINDOW_HEIGHT", 700);
    enc.add_data<int>("WINDOW_WIDTH", 1300);
    // Game setting
        // bool isRaining = false;
        // bool isLightning = false;
        // bool isBirds = false;
        // bool isBalloon = false;
        // bool isFireworks = false;
        // bool isBlackhole = false;
    enc.add_data<int>("isRaining", 0);
    enc.add_data<int>("isLightning", 0);
    enc.add_data<int>("isBirds", 0);
    enc.add_data<int>("isBalloon", 0);
    enc.add_data<int>("isFireworks", 0);
    enc.add_data<int>("isBlackhole", 0);
    // Volume
        // float masterVolume = 0.0;
        // float rainVolume = 100.0;
        // float thunderVolume = 100.0;
        // float birdsVolume = 100.0;
        // float fireworksVolume = 100.0;
        // float backgroundVolume = 100.0;
    enc.add_data<float>("masterVolume", (float) 0.0);
    enc.add_data<float>("rainVolume", (float) 100.0);
    enc.add_data<float>("thunderVolume", (float) 100.0);
    enc.add_data<float>("birdsVolume", (float) 100.0);
    enc.add_data<float>("fireworksVolume", (float) 100.0);
    enc.add_data<float>("backgroundVolume", (float) 100.0);
    enc.updatefile();


    cout << enc.get_item<int>("WINDOW_HEIGHT") << endl;
    cout << enc.get_item<int>("WINDOW_WIDTH") << endl;
    cout << endl;

    cout << enc.get_item<int>("isRaining") << endl;
    cout << enc.get_item<int>("isLightning") << endl;
    cout << enc.get_item<int>("isBirds") << endl;
    cout << enc.get_item<int>("isBalloon") << endl;
    cout << enc.get_item<int>("isFireworks") << endl;
    cout << enc.get_item<int>("isBlackhole") << endl;
    cout << endl;

    cout << enc.get_item<float>("masterVolume") << endl;
    cout << enc.get_item<float>("rainVolume") << endl;
    cout << enc.get_item<float>("thunderVolume") << endl;
    cout << enc.get_item<float>("birdsVolume") << endl;
    cout << enc.get_item<float>("fireworksVolume") << endl;
    cout << enc.get_item<float>("backgroundVolume") << endl;

    return 0;
}
