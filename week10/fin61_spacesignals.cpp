#include <iostream>

using namespace std;

int main(){
    string s;
    string t;
    cin >> s;
    cin >> t;
    int count=0;
    auto it_s = s.begin();
    for (auto it = t.begin();it != t.end();it++){
        if (*it_s == *it)
            it_s++;
        if (it_s == s.end()) {
            count++;
            it_s = s.begin();
        }
    }
    cout << count;
    return 0;
}