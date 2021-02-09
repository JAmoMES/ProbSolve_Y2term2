#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        q.push({x,y});
    }
    int day = 0,cost = 0,maxx = 0;
    while(!q.empty()){
        auto x = q.top();
        q.pop();
        day+=x.second;
        if(day > x.first + 10)
            cost = (day-x.first-10)*1000;
        maxx = max(maxx,cost);
    }
    cout << maxx;
    return 0;
}