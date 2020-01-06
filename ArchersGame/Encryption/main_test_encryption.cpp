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
        int isRaining = 0;
        int isLightning = 0;
        int isBirds = 1;
        int isBalloon = 0;
        int isFireworks = 0;
        int isBlackhole = 0;
    // Volume
        float masterVolume = 100.0;
        float rainVolume = 100.0;
        float thunderVolume = 100.0;
        float birdsVolume = 100.0;
        float fireworksVolume = 100.0;
        float backgroundVolume = 100.0;

    enc.add_data<int>("background",background);
    enc.add_data<int>("WINDOW_HEIGHT",WINDOW_HEIGHT);
    enc.add_data<int>("WINDOW_WIDTH",WINDOW_WIDTH);
    enc.add_data<int>("isRaining",isRaining);
    enc.add_data<int>("isLightning",isLightning);
    enc.add_data<int>("isBirds",isBirds);
    enc.add_data<int>("isBalloon",isBalloon);
    enc.add_data<int>("isFireworks",isFireworks);
    enc.add_data<int>("isBlackhole",isBlackhole);
    enc.add_data<float>("masterVolume",masterVolume);
    enc.add_data<float>("rainVolume",rainVolume);
    enc.add_data<float>("thunderVolume",thunderVolume);
    enc.add_data<float>("birdsVolume",birdsVolume);
    enc.add_data<float>("fireworksVolume",fireworksVolume);
    enc.add_data<float>("backgroundVolume",backgroundVolume);
    enc.updatefile();

    cout<<"background = "<<enc.get_item<int>("background")<<'\n';
    cout<<"WINDOW_HEIGHT = "<<enc.get_item<int>("WINDOW_HEIGHT")<<'\n';
    cout<<"WINDOW_WIDTH = "<<enc.get_item<int>("WINDOW_WIDTH")<<'\n';
    cout<<"isRaining = "<<enc.get_item<int>("isRaining")<<'\n';
    cout<<"isLightning = "<<enc.get_item<int>("isLightning")<<'\n';
    cout<<"isBirds = "<<enc.get_item<int>("isBirds")<<'\n';
    cout<<"isBalloon = "<<enc.get_item<int>("isBalloon")<<'\n';
    cout<<"isFireworks = "<<enc.get_item<int>("isFireworks")<<'\n';
    cout<<"isBlackhole = "<<enc.get_item<int>("isBlackhole")<<'\n';
    cout<<"masterVolume = "<<enc.get_item<float>("masterVolume")<<"\n";
    cout<<"rainVolume = "<<enc.get_item<float>("rainVolume")<<"\n";
    cout<<"thunderVolume = "<<enc.get_item<float>("thunderVolume")<<"\n";
    cout<<"birdsVolume = "<<enc.get_item<float>("birdsVolume")<<"\n";
    cout<<"fireworksVolume = "<<enc.get_item<float>("fireworksVolume")<<"\n";    
    cout<<"backgroundVolume = "<<enc.get_item<float>("backgroundVolume")<<"\n";

    return 0;
}
