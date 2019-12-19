#include "Encryption.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    Encrypt enc;
/*
    enc.add_data<int>("damage",100);
    enc.add_data<float>("size",100.5);
    enc.add_data<long long>("remaining_health",1031314567899);
*/
    cout<<"damage = "<<enc.get_item<int>("damage")<<'\n';
    cout<<"size = "<<enc.get_item<float>("size")<<"\n";
    cout<<"remaining_health = "<<enc.get_item<long long>("remaining_health")<<'\n';
    cout<<"gay = "<<enc.get_item<int>("gay")<<'\n';
    enc.add_data<int>("gay",104);
    enc.updatefile();
/*
    ostringstream line;
    ifstream fin;
    fin.open("Constants.txt", ios::in);
    char my_character ;
	while (!fin.eof() ) {
        fin.get(my_character);
        if (my_character!='\n'){
            line << my_character;
        }
        if (my_character=='\n'){
            cout<<line.str()<<'\n';
            cout<<enc.decrypt(line.str())<<'\n';
            line.str("");
            line.clear();

            //cout<<enc.decrypt(line);
        }

	}

	//cout<< enc.decrypt("UHutrqeUX(<aL$]MP :}");
	enc.updatefile();
	cout<<'\n';
	istringstream buffer("5");
	int temp;
    buffer >> temp;
    int y = 3 + temp;
    cout<<y;
    */
    return 0;
}
