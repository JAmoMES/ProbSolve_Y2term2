#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        pair<int,int> cover = {0,m};
        int l,r;
        vector<pair<int,int>> seg;
        while(cin >> l >> r , l||r){
            seg.emplace_back(l,r);
        }
//        vector<pair<int,int>> ans;
//        sort(seg.begin(),seg.end());
//        for(int i =0;i<seg.size();i){
//            if(seg[i].first > cover.first) break;
//            for(i++;i<seg.size();i++){
//
//            }
//        }
    }
    return 0;
}