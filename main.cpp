#include<iostream>
#include<string.h>
#include<vector>
#include <cmath>
using namespace std;
std::string chaos(const std::string& source, float key) {
    std::string new_str;
    new_str.reserve(source.size());
    int xt = round(1 - 2 * std::abs(key));
    for (char c : source) {
        new_str += static_cast<char>(c + xt);
        xt = round(1 - 2 * std::abs(xt));
    }

    return new_str;
}
std::string de_chaos(const std::string& source, float key) {
    std::string new_str;
    new_str.reserve(source.size());
    int xt = round(1 - 2 * std::abs(key));
    for (char c : source) {
        new_str += static_cast<char>(c - xt);
        xt = round(1 - 2 * std::abs(xt));
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
