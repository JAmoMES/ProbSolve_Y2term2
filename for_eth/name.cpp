#include <iostream>
#include <string>
using namespace std;

string social;
string name;

int main(){
    cin >> name;
    cin >> social;
    int count = 0;
    auto it2 = name.begin();
    for(auto it = social.begin();it!=social.end();it++){
//        cout << *it << " " << *it2 << '\n;
        if(*it == *it2) it2++;
        if(it2 == name.end()){
            count++;
            it2 = name.begin();
        }
    }
    cout << count;
    return 0;
}
