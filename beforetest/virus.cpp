#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    list<int> l;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        l.push_back(x);
    }
    auto it = l.begin();
    for(int i=0;i<m;i++){
        int command;
        cin >> command;
        switch (command) {
            case 1:
                it = l.begin();
                break;
            case 2:
                if(++it == l.end())
                    it = l.begin();
                break;
            case 3:
                int x;
                cin >> x;
                l.insert(it,x);
                break;
            case 4:
                cin >> x;
                l.insert(++it,x);
                it--;
                it--;
                break;
        }
    }
    for(auto it:l)
        cout << it << '\n';
    return 0;
}