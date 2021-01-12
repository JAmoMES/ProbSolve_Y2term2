#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,m;
    set<int> s;
    s.insert(1000000001);
    s.insert(-1000000001);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i=0;i<m;i++){
        int y;
        cin >> y;
        auto it = s.lower_bound(y);
        auto it1 = s.upper_bound(y);
        if(it == it1) it--;
        if(y-*it <= *it1-y || *it1 == 1000000001)
            cout << *it << "\n";
        else cout << *it1 << "\n";
    }
    return 0;
}