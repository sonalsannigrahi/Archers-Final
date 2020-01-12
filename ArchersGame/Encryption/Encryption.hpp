#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <typeinfo>
#include <fstream>
#include <sstream>
using namespace std;
class Encrypt{
private:
    //randomize the encryption
    vector<vector<int> > r;
    vector<vector<char> > s;
    //ENCRYPTED DICTIONARY WITH ALL DATA HERE:
    map<string,int> sint;
    map<string,float> sfloat;
    map<string,double> sdouble;
    map<string,long long> sllong;
    map<string,string> sstring;


    //
public:
    //CREATE RANDOM FLOAT r
    //MAKE THE ENCRYPTED DICTIONARY
    Encrypt();

    ~Encrypt();
     string encrypt(string word);
    //encrypt an integer
    int encrypt(int number);
    //encrypt a float
    float encrypt(float number);
    //encrypt a double
    double encrypt(double number);
    //encrypt a long long
    long long encrypt(long long number);
    //encrypt a string
   
    //decrypt an integer
    int decrypt(int number);
    //decrypt a float
    float decrypt(float number);
    //decrypt a double
    double decrypt(double number);
    //decrypt a long long
    long long decrypt(long long number);
    //decrypt a string
    string decrypt(string word);
    // get the decrypted data back
    string get_item_string(string key);
    template <typename T> T get_item(string key);
    //add data
    void add_data_string(string key, string value);
    template <typename U> void add_data(string key, U value);
    int updatefile();
};
template <typename T> T Encrypt::get_item(string key){
    T type;
    int int_;
    float float_;
    double double_;
    long long long_long;
    string string_ = "";
    if (typeid(type)==typeid(int_)){
        for (map<string, int>::iterator itr = sint.begin(); itr != sint.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                return this->decrypt(itr->second);
            }
        }
    }
    else if (typeid(type)==typeid(float_)){
        for (map<string, float>::iterator itr = sfloat.begin(); itr != sfloat.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                return this->decrypt(itr->second);
            }
        }
    }
    else if (typeid(type)==typeid(double_)){
        for (map<string, double>::iterator itr = sdouble.begin(); itr != sdouble.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                return this->decrypt(itr->second);
            }
        }
    }
    else if (typeid(type)==typeid(long_long)){
        for (map<string, long long>::iterator itr = sllong.begin(); itr != sllong.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                return this->decrypt(itr->second);
            }
        }
    }
    
    
    

}
template <typename U> void Encrypt::add_data(string key, U value){
    U type;
    int int_;
    float float_;
    double double_;
    long long long_long;
    string string_;
    if (typeid(value)==typeid(int_)){
        for (map<string, int>::iterator itr = sint.begin(); itr != sint.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                sint.erase(this->encrypt(key));
            }
        }

        sint.insert(pair<string,int> (this->encrypt(key),this->encrypt(value)));
    }
    else if (typeid(value)==typeid(float_)){
        for (map<string, float>::iterator itr = sfloat.begin(); itr != sfloat.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                sfloat.erase(this->encrypt(key));
            }
        }
         //cout<<typeid(this->encrypt(value)).name()<<endl;
        sfloat.insert(pair<string,float> (this->encrypt(key),this->encrypt(value)));
    }
    else if (typeid(value)==typeid(double_)){
        for (map<string, double>::iterator itr = sdouble.begin(); itr != sdouble.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                sdouble.erase(this->encrypt(key));
            }
        }
        sdouble.insert(pair<string,double> (this->encrypt(key),this->encrypt(value)));
    }
    else if (typeid(value)==typeid(long_long)){
        for (map<string, long long>::iterator itr = sllong.begin(); itr != sllong.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                sllong.erase(this->encrypt(key));
            }
        }
       
        sllong.insert(pair<string,long long> (this->encrypt(key),this->encrypt(value)));
    }

    
    
}
