#include <iostream>
#include <list>
using namespace std;

int main(){
    int m,x;
    cin >> m;
    list<int> l;
    string s[4] = {"li","ri","lr","rr"};
    for(int i=0;i<m;i++){
        string command;
        cin >> command;
        if(command == s[0]){
            cin >> x;
            l.push_front(x);
        }
        else if(command == s[1]){
            cin >> x;
            l.push_back(x);
        }
        else if(command == s[2]){
            if (l.empty()) continue;
            x = l.front();
            l.pop_front();
            l.push_back(x);
        }
        else if(command == s[3]){
            if (l.empty()) continue;
            x = l.back();
            l.pop_back();
            l.push_front(x);
        }
    }
    for(auto it : l)
        cout << it << endl;
    return 0;
}