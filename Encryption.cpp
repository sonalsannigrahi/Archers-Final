#include "GitHub\Archers\Encryption.hpp"
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand
using namespace std;
Encrypt::Encrypt(){
    vector<vector<int> >   vect;
    for (int i=0; i<10; ++i){
        vector<int> temp1;
        if (i==0){
            for (int k=0; k<10; ++k){
                temp1.push_back(k);
            }
            random_shuffle ( temp1.begin(), temp1.end() );
            vect.push_back(temp1);
        }
        else{
            vector<int> temp = vect[i-1];
            int k = temp[0];
            temp.erase(temp.begin());
            temp.push_back(k);
            vect.push_back(temp);
        }
    }
    r = vect;


    vector<vector<char> > vecto;
    for (int i=32; i<127; ++i){
        vector<char> temp_1;
        if (i==32){
            for (char k=32; k<127; ++k){
                temp_1.push_back(k);
            }
            random_shuffle ( temp_1.begin(), temp_1.end() );
            vecto.push_back(temp_1);
        }
        else{
            vector<char> temp_ = vecto[i-32-1];
            char k = temp_[0];
            temp_.erase(temp_.begin());
            temp_.push_back(k);
            vecto.push_back(temp_);
        }
    }
    s = vecto;
    //DICTIONARY IMPLEMENTATION
}
Encrypt::~Encrypt(){
}
int Encrypt::encrypt(int number){
    vector<int> nu;
    int count_= number;
    while(count_ > 0){
        int tempdig = count_%10;
        count_ = (count_-tempdig)/10;
        nu.insert(nu.begin(), tempdig);
    }
    int result=0;
    int c;
    int temp;
    for(int i=0;i<nu.size();i++){
        c  = 0;
        temp = r[i%10][c];
        while(temp!=nu[i]){
            c++;
            temp=r[i%10][c];
        }
        result = 10*result + c;
    }
    return result;
}
int Encrypt::decrypt(int number){
    int result=0;
    vector<int> nu;
    int count_= number;
    while(count_ > 0){
        int tempdig = count_%10;
        count_ = (count_-tempdig)/10;
        nu.insert(nu.begin(), tempdig);
    }
    for(int k =0; k<nu.size();k++){
        int ind = nu[k];
        result = result*10 + r[k%10][ind];
    }
    return result;
}
float Encrypt::encrypt(float number){
    if (number==(float)(int)(number)){
        return (float)(this->encrypt((int)(number)));
    }
    float nnumber = number;
    int k=1;
    while (nnumber!=(float)(int)(nnumber)){
        nnumber=nnumber*10;
        k = k*10;
    }
    float res = (float)(this->encrypt(nnumber))/(float)(k);
    return res;
}
float Encrypt::decrypt(float number){
    if (number==(float)(int)(number)){
        return (float)(this->encrypt((int)(number)));
    }
    float nnumber = number;
    int k=1;
    while (nnumber!=(float)(int)(nnumber)){
        nnumber=nnumber*10;
        k = k*10;
    }
    float res = (float)(this->decrypt(nnumber))/(float)(k);
    return res;
}
double Encrypt::encrypt(double number){
    if (number==(double)(long long)(number)){
        return (double)(this->encrypt((long long)(number)));
    }
    double nnumber = number;
    long long k=1;
    while (nnumber!=(double)(long long)(nnumber)){
        nnumber=nnumber*10;
        k = k*10;
    }
    double res = (double)(this->encrypt(nnumber))/(double)(k);
    return res;
}
double Encrypt::decrypt(double number){
    if (number==(double)(long long)(number)){
        return (double)(this->encrypt((long long)(number)));
    }
    double nnumber = number;
    long long k=1;
    while (nnumber!=(double)(long long)(nnumber)){
        nnumber=nnumber*10;
        k = k*10;
    }
    double res = (double)(this->decrypt(nnumber))/(double)(k);
    return res;
}
long long Encrypt::encrypt(long long number){
    vector<int> nu;
    long long count_= number;
    while(count_ > 0){
        int tempdig = count_%10;
        count_ = (count_-tempdig)/10;
        nu.insert(nu.begin(), tempdig);
    }
    long long result=0;
    long long c;
    long long temp;
    for(int i=0;i<nu.size();i++){
        c  = 0;
        temp = r[i%10][c];
        while(temp!=nu[i]){
            c++;
            temp=r[i%10][c];
        }
        result = 10*result + c;
    }
    return result;
}
long long Encrypt::decrypt(long long number){
    long long result=0;
    vector<int> nu;
    long long count_= number;
    while(count_ > 0){
        int tempdig = count_%10;
        count_ = (count_-tempdig)/10;
        nu.insert(nu.begin(), tempdig);
    }
    for(int k =0; k<nu.size();k++){
        int ind = nu[k];
        result = result*10 + r[k%10][ind];
    }
    return result;
}
string Encrypt::encrypt(string word){
    int c;
    char temp;
    string word_= word;
    for(int i=0;i<word.length();++i){
        c = 0;
        temp = s[i][c];
        while(temp!=word_[i]){
            c++;
            temp=s[i][c];
        }
        word_[i] = (char)(c+32);
    }
    return word_;
}
string Encrypt::decrypt(string word){
    string word_= word;
    int c;
    for(int i=0;i<word.length();++i){
        c = (int)(word[i]) - 32;
        word_[i] = s[i][c];
    }
    return word_;
}
