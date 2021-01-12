#include <iostream>
#include <map>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x=0,y=0;
    cin >> n >> m;
    map<int,list<pair<int,int>>> bottle;
    int a[n+2];
    a[0] = 0;
    a[n+1] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        bottle[a[i]].push_back(make_pair(a[i-1],a[i+1]));
    }
//    for(auto it = bottle.begin();it != bottle.end();it++){
//        cout << it->first << "-> ";
//        for(auto it1 : it->second)
//            cout << "(" << it1.first << "," << it1.second << ") ";
//        cout << "\n";
//    }
    for(int i=0;i<m;i++){
        int high,count = 0;
        cin >> high;
        for(auto it = bottle.rbegin();it->first > high;){
            for(auto it1:it->second){
                if(it1.first <= high) {
                    for (auto it2 = bottle[it1.first].begin(); it2 != bottle[it1.first].end(); it2++){
                        if (it2->first == it->first || it2->second == it->first) {
                            count++;
                            bottle[it1.first].erase(it2--);
                        }
                    }
                }
                if(it1.second <= high) {
                    for (auto it2 = bottle[it1.second].begin(); it2 != bottle[it1.second].end(); it2++){
                        if (it2->first == it->first || it2->second == it->first) {
                            count++;
                            bottle[it1.second].erase(it2--);
                        }
                    }
                }
                count++;
            }
            bottle.erase(it->first);
        }
        cout << count << "\n";
//        for(auto it3 = bottle.begin();it3 != bottle.end();it3++){
//            cout << it3->first << "-> ";
//            for(auto it1 : it3->second)
//                cout << "(" << it1.first << "," << it1.second << ") ";
//            cout << "\n";
//        }
    }
    return 0;
}
/*
7 5
3
1
7
7
7
3
5
5
4
6
2
 */
