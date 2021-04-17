#include <iostream>
#include <queue>

using namespace std;

#define MxN 30
#define INF 1<<30

char a[MxN+1][MxN+1];
int cost[MxN+1][MxN+1];

typedef pair<int,pair<int,int>> tri;

int dijkstra(int n,int m){
    priority_queue<tri, vector<tri> ,greater<tri>> pq;
    for(int i=1;i<n+1;i++){
        for (int j = 1; j <m+1 ; ++j) {
            cost[i][j] = INF;
        }
    }
    cost[1][1] = 0;
    pq.push({0,{1,1}});
    while(!pq.empty()){
        int w = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
//        cout << x << ' ' << y << ' ' << w << '\n';
        if(cost[x][y] < w) continue;
        if (x>1 && a[x-1][y]!='X') {
            if (cost[x-1][y] > cost[x][y]){
                cost[x-1][y] = cost[x][y];
                pq.push({cost[x-1][y],{x-1,y}});
            }
        }
        if (y>1 && a[x][y-1]!='X') {
            if (cost[x][y-1] > cost[x][y]+1){
                cost[x][y-1] = cost[x][y]+1;
                pq.push({cost[x][y-1],{x,y-1}});
            }
        }
        if (x<n && a[x+1][y]!='X') {
            if (cost[x+1][y] > cost[x][y] + 5) {
                cost[x + 1][y] = cost[x][y] + 5;
                pq.push({cost[x + 1][y], {x + 1, y}});
            }
        }
        if (y<m && a[x][y+1]!='X') {
            if (cost[x][y+1] > cost[x][y] + 1) {
                cost[x][y+1] = cost[x][y] + 1;
                pq.push({cost[x][y+1], {x, y+1}});
            }
        }
    }
    if (cost[n][m] == 1<<30)
        return -1;
    return cost[n][m];
}


int main(){
    int n,m;
    cin >> n >> m;
    for (int i=n;i>0;i--){
        for (int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    cout << dijkstra(n,m);
    return 0;
}
