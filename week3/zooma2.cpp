#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
    list<pair<int,int>> l;
    vector<list<pair<int,int>>::iterator> it;
    int n,m;
    cin >> n >> m;
    for(int i =0 ;i<n ;i++){
        int color;
        cin >> color;
        l.push_back(make_pair(color,i+1));
        auto it1 = l.end();
        it.push_back(--it1);
    }
    for(int i =0 ;i<m;i++){
        int color,after;
        cin >> color >> after;
        auto it1 = it[after-1];
        if(it1 != l.end())
            l.insert(++it1,make_pair(color,n+i+1));
        else {
            it.push_back(l.end());
            continue;
        }
        auto it2 = it1--;
        int same = 1;
        while(it2!=l.end()){
            if(it2->first != color) break;
            it2++;
            same++;
        }
        if(same>=3) {
            for(auto it3 = it1;it3!=it2;it3++) {
                it[it3->second-1] = l.end();
            }
            l.erase(it1,it2);
            it.push_back(l.end());
        }
        else it.push_back(it1);
    }
    for(auto it1:l)
        cout << it1.second << "\n";
    return 0;
}