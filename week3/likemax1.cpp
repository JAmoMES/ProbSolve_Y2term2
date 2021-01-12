#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int,int> status;
    pair<int,int> top_like = make_pair(0,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        status[x]++;
        if(top_like.second <= status[x]){
            top_like.first = x;
            top_like.second = status[x];
        }
        cout << top_like.first << "\n";
    }
    return 0;
}