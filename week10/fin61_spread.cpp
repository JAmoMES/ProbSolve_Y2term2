#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define INF 1<<30
#define MxN 100000
vector<pair<int,int>> v[MxN+1];
bool visited[MxN+1];
int dis[MxN+1];
int n,m;

int mst(int start){
    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }
    int maxx = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    dis[start] = 0;
    while(!q.empty()){
        auto x = q.top();
        int node = x.second;
        q.pop();
        if(visited[node]) continue;
        maxx = max(maxx,dis[node]);
        visited[node] = true;
        for(auto it:v[node]){
            if(!visited[it.first]&&dis[it.first] > it.second) {
                dis[it.first] = it.second;
                q.push({it.second ,it.first});
            }
        }
    }
//    for (int i=1;i<=n;i++){
//        cout << dis[i] << ' ';
//    }
    return maxx;
}

int main(){
    cin >> n >> m;
    int spread[n+1];
    for (int i=1;i<=n;i++){
        cin >> spread[i];
    }
    for (int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        int d = (int) ceil((float)(w)/((float)(spread[x]+spread[y])));
//        cout << d << '\n';
        v[x].emplace_back(y,d);
        v[y].emplace_back(x,d);
    }
    cout << mst(1);
    return 0;
}