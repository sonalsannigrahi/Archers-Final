#include "Encryption.hpp"
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <cstdlib>
#include <iterator>
#include <map>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
Encrypt::Encrypt(){
    vector<vector<int> >   vect;
    for (int i=0; i<10; ++i){
        vector<int> temp1;
        if (i==0){
            for (int k=0; k<10; ++k){
                temp1.push_back(k);
            }
            //random_shuffle ( temp1.begin(), temp1.end() );
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
            //random_shuffle ( temp_1.begin(), temp_1.end() );
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
    ifstream fin;
    vector<string> lines;
    fin.open("Constants.txt", ios::in);
    char my_character ;
    ostringstream line;
	while (!fin.eof() ) {
        fin.get(my_character);
        if (my_character != '\n'){
                line << my_character;
        }
        if (my_character == '\n'){
            lines.push_back(decrypt(line.str()));
            line.str("");
            line.clear();
        }
    }
    int pos_of_eq = 1000;
    int pos_of_y = 1000;
    ostringstream ss;
    ostringstream nn;
    ostringstream tt;
    for(int k = 0;k<lines.size();k++){
        ss.str("");
        ss.clear();
        nn.str("");
        nn.clear();
        tt.str("");
        tt.clear();
        pos_of_eq = 1000;
        pos_of_y = 1000;
        for(int i=0;i<lines[k].length();++i){
            if((lines[k][i]=='t') && (lines[k][i+1]== 'y') && (lines[k][i+2]=='p')){
                    pos_of_y = i+1;
            }

            else if((lines[k][i]==' ') && (lines[k][i+1]== '=') && (lines[k][i+2]==' ')){
                    pos_of_eq = i+1;
            }
            else if((i> pos_of_eq + 1) && (i< pos_of_y )){
                nn<<lines[k][i];
            }
            else if (i> pos_of_y + 1){
                tt<<lines[k][i];
            }

            else if ((i!=pos_of_y)&&(i!=pos_of_y-1)&&(i!=pos_of_eq)&&(i!=pos_of_eq-1)&&(i!=pos_of_y+1)&&(i!=pos_of_eq+1) ){
                    ss<<lines[k][i];

            }


        }
        cout<<ss.str()<< "---"<<nn.str()<< "---"<< tt.str()<<endl;
        if (tt.str()=="double"){
                istringstream buffer(nn.str());
                double temp;
                buffer >> temp;
                sdouble.insert(pair<string,double> (ss.str(),temp));
        }
        else if (tt.str()=="int"){
                istringstream buffer(nn.str());
                int temp;
                buffer >> temp;
                sint.insert(pair<string,int> (ss.str(),temp));
        }
        else if (tt.str()=="float"){
                istringstream buffer(nn.str());
                float temp;
                buffer >> temp;
                sfloat.insert(pair<string,float> (ss.str(),temp));
        }
        else if (tt.str()=="llong"){
                istringstream buffer(nn.str());
                long long temp;
                buffer >> temp;
                sllong.insert(pair<string,long long> (ss.str(),temp));

        }
        
        else if (tt.str()=="string"){
                sstring.insert(pair<string,string> (ss.str(),nn.str()));

        }
        


    }

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
        return (float)(this->decrypt((int)(number)));
    }
    float nnumber = number;
    int k=1;
    while (nnumber!=(float)(int)(nnumber)){
        nnumber=nnumber*10;
        k = k*10;
    }
    float res = ((float)(this->decrypt((int)nnumber)))/(k);
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
        return (double)(this->decrypt((long long)(number)));
    }
    double nnumber = number;
    long long k=1;
    while (nnumber!=(double)(long long)(nnumber)){
        nnumber=nnumber*10;
        k = k*10;
    }
    double res = (double)(this->decrypt((int)(nnumber)))/(k);
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
int Encrypt::updatefile(){
    ofstream outdata; // outdata is like cin
    int i; // loop index
    outdata.open("Constants.txt"); // opens the file
    if( !outdata ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    map<string, int>::iterator itri;
    map<string, float>::iterator itrf;
    map<string, long long>::iterator itrll;
    map<string, double>::iterator itrd;
    map<string, string>::iterator itrs;
    ostringstream ss;
    string en;
    for (itri=sint.begin(); itri!=sint.end(); ++itri) {
        ss << itri->first << " = " << itri->second << "typ" << "int";
        //cout<<ss.str();
        en = this->encrypt(ss.str());
        //cout<<en;
        outdata << en << endl;
        //outdata<< ss.str()<< endl;
        ss.str("");
        ss.clear();
    }
    for (itrf=sfloat.begin(); itrf!=sfloat.end(); ++itrf){
        ss << itrf->first << " = " << itrf->second << "typ" << "float";
        //cout<<ss.str()<<endl;
        en = this->encrypt(ss.str());
        outdata << en << endl;
        //outdata<< ss.str()<< endl;
        ss.str("");
        ss.clear();
    }
    ss.clear();
    for (itrd=sdouble.begin(); itrd!=sdouble.end(); ++itrd){
        ss << itrd->first << " = " << itrd->second << "typ" << "double";
        //cout<<ss.str()<<endl;
        en = this->encrypt(ss.str());
        outdata << en << endl;
        //outdata<< ss.str()<< endl;
        ss.str("");
        ss.clear();
        }
    for (itrll=sllong.begin(); itrll!=sllong.end(); ++itrll) {
        ss << itrll->first << " = " << itrll->second << "typ" << "llong";
        //cout<<ss.str()<<endl;
        en = this->encrypt(ss.str());
        outdata << en << endl;
        //outdata<< ss.str()<< endl;
        ss.str("");
        ss.clear();
        }
    
    for (itrs=sstring.begin(); itrs!=sstring.end(); ++itrs) {
        ss << itrs->first << " = " << itrs->second << "typ" << "string";
        //cout<<ss.str()<<endl;
        en = this->encrypt(ss.str());
        outdata << en << endl;
        //outdata<< ss.str()<< endl;
        ss.str("");
        ss.clear();
        }
    
    outdata.close();
    return 0;
}

void Encrypt::add_data_string(string key, string value){
    
        for (map<string, string>::iterator itr = sstring.begin(); itr != sstring.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                sstring.erase(this->encrypt(key));
            }
        }
        //string y = this->encrypt(value);
        sstring.insert(pair<string, string> ( encrypt(key) , encrypt(value) ));
}
string Encrypt::get_item_string(string key){

        for (map<string, string>::iterator itr = sstring.begin(); itr != sstring.end(); ++itr) {
            if (itr->first== this->encrypt(key)){
                return this->decrypt(itr->second);
            }
        }
    
}

