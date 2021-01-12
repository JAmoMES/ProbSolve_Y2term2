#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
    list<int> l;
    vector<list<int>::iterator> it;
    int n,m;
    cin >> n >> m;
    for(int i =0 ;i<n ;i++){
        int color;
        cin >> color;
        l.push_back(i+1);
        auto it1 = l.end();
        it.push_back(--it1);
    }
    for(int i =0 ;i<m;i++){
        int color,after;
        cin >> color >> after;
        auto it1 = it[after-1];
        l.insert(++it1,n+i+1);
        it.push_back(--it1);
    }
    for(auto it1:l)
        cout << it1 << "\n";
    return 0;
}