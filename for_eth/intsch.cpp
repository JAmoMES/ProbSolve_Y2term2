#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>> q;
    for(int i=0;i<n ;i++){
        int x,y;
        cin >> x >> y;
        q.push({y,x});
    }
    int d = 0,count=0;
    while(!q.empty()){
        auto x = q.top();
        q.pop();
        if(d <= x.second){
            count ++;
            d = x.first;
        }
    }
    cout << count;
    return 0;
}