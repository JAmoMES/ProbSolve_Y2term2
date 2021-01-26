#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    int tall[n+1];
    int min = 1000000001;
    tall[0] = 1000000001;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        if(x < min) min = x;
        tall[i+1] = min;
    }
    map<int,int> pos;
    for(int i=0;i<=n;i++){
        pos[tall[i]] = i;
    }
    for(int i=0;i<q;i++){
        int command;
        cin >> command;
        switch (command) {
            case 1:
                int j;
                cin >> j;
                cout << tall[j] << '\n';
                break;
            case 2:
                int k;
                cin >> k;
                auto it = pos.lower_bound(k);
                cout << it->second << '\n';
                break;
        }
    }
    return 0;
}
