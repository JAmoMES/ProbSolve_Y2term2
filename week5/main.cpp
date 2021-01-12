#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string str;
    while(getline(cin,str) && !str.empty()){
        cout << str << "\n";
        string str1,str2;
        stringstream ss(str);
        ss >> str1 >> str2;
        cout << str1 << "&&" << str2 << "\n";
    }
    return 0;
}
