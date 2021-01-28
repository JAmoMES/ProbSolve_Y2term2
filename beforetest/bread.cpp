#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    map<int,pair<int,int>> bread_shop;
    for(int i=0;i<n;i++){
         int x,y,z;
         cin >> x >> y >> z;
         bread_shop[x] = {y,z};
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        int buy = 1000001 , pos;
        auto l = bread_shop.lower_bound(x-5);
        auto u = bread_shop.upper_bound(x+5);
        for(auto it = l ;it != u;it++){
            //cout << it->first << " ";
            if(buy > it->second.first){
                buy = it->second.first;
                pos = it->first;
            }
        }
        if(buy == 1000001){
            cout << "0\n";
            continue;
        }
        else{
            cout << buy << "\n";
            bread_shop[pos].second--;
            if(bread_shop[pos].second == 0)
                bread_shop.erase(pos);
        }
    }
    return 0;
}