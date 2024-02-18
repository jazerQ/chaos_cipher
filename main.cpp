#include<iostream>
#include<string.h>
#include<vector>
#include <cmath>
using namespace std;
string chaos(std::string source,float key){
    string new_str = "";
    vector<int> xt_arr = {};
    xt_arr.push_back(key);
    int xt = round(1-2*abs(key));
    xt_arr.push_back(xt);
    for(int i = 0;i < source.size();i++){
        new_str += static_cast<char>((int) source[i] + xt_arr[i+1]);
        xt_arr.push_back(round(1-2*abs(xt_arr[i+1])));
    }
    return new_str;
}
string de_chaos(std::string source,float key){
    string new_str = "";
    vector<int> xt_arr = {};
    xt_arr.push_back(key);
    int xt = round(1-2*abs(key));
    xt_arr.push_back(xt);
    for(int i = 0;i < source.size();i++){
        new_str += static_cast<char>((int) source[i] - xt_arr[i+1]);
        xt_arr.push_back(round(1-2*abs(xt_arr[i+1])));
    }
    return new_str;
}
int main(){
    string word;
    cout << "vvedi word >";
    cin >> word;
    cout << "vvedi key from (0;1)";
    float key;
    cin >> key;
    string code = chaos(word,key);
    string decode = de_chaos(code,key);
    cout << "\n new chaos =>"<< code << "\n";
    cout << "de_chaos =>" << decode;
    return 0;
}
