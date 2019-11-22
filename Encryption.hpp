#pragma once
#include <iostream>
using namespace std;
class Encrypt{
private:
    //randomize the encryption
    float r;
    //ENCRYPTED DICTIONARY WITH ALL DATA HERE:
//  .....
    //
public:
    //CREATE RANDOM FLOAT r
    //MAKE THE ENCRYPTED DICTIONARY
    void Encrypt();

    void ~Encrypt();
    //encrypt an integer
    int encrypt(int number);
    //encrypt a float
    float encrypt(float number);
    //encrypt a double
    double encrypt(double number);
    //encrypt a long long
    long long encrypt(long long number);
    //encrypt a string
    string encrypt(string word);
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
    template <typename T, typename U > T get_item(U object);

};
