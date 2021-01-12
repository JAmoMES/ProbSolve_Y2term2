#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l[100001];
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        char command;
        int x,y;
        cin >> command;
        if(command == 'N'){
            cin >> x >> y;
            l[y].push_back(x);
        }
        else{
            cin >>x >> y;
            l[y].splice(l[y].end(),l[x]);
            l[x].clear();
        }
    }
    for(int i =1 ;i<100001;i++){
        for(auto it = l[i].begin();it != l[i].end();it++){
            cout << *it << endl;
        }
    }
    return 0;
}