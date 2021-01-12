#include <iostream>
#include <list>
using namespace std;

int main() {
    int m;
    cin >> m;
    list<int> l;
    for(int i=0;i<m;i++){
        char command;
        int x;
        cin >> command >> x;
        if (command == 'I'){
            l.push_front(x);
        }
        else if(command == 'D'){
            if(x>l.size()) continue;
            auto p = l.begin();
            advance(p,x-1);
            l.erase(p);
        }
    }
    for(auto it = l.begin();it != l.end();it++){
        cout << *it << endl;
    }
    return 0;
}
