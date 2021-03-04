#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;

typedef pair<int,pair<int,int>> tri;
int dis[1001];

int dijkstra(int n,vector<pair<int,int>> v[]){
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
    for(int i=1;i<n+1;i++){
        dis[i] = INF;
    }
    dis[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        auto x = q.top();
        int now = x.second;
        q.pop();
        if(dis[now] < x.first) continue;
        for(auto it:v[x.second]){
            int next = it.first;
            int w = it.second;
            if(dis[next] > dis[now] + w) {
                dis[next] = dis[now] + w;
                q.push({dis[next], next});
            }
        }
    }
    return dis[n];
}

int dijkstra2(int n,vector<pair<int,int>> v[],int start,int stop,int weight){
    int distance[n+1];
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
    for(int i=1;i<n+1;i++){
        distance[i] = dis[i];
    }
    distance[stop] = distance[start] + weight;
    q.push({distance[stop],stop});
    while(!q.empty()){
        auto x = q.top();
        int now = x.second;
        q.pop();
        if(distance[now] < x.first) continue;
        for(auto it:v[x.second]){
            int next = it.first;
            int w = it.second;
            if(distance[next] > distance[now] + w) {
                distance[next] = distance[now] + w;
                q.push({distance[next], next});
            }
        }
    }
    return distance[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > v[n+1];
    vector<tri> speed;
    for(int i=0;i<m;i++){
        int x,y,w,s;
        cin >> x >> y >> w >> s;
        if(s) speed.push_back({x,{y,w}});
        else {
            v[x].emplace_back(y, w);
            v[y].emplace_back(x, w);
        }
    }

    int min_dis = INF;
    min_dis = min(min_dis,dijkstra(n,v));
    for(auto it : speed){
        int x = it.first;
        int y = it.second.first;
        int w = it.second.second;
        if(dis[x] > dis[y]) swap(x,y);
        min_dis = min(min_dis,dijkstra2(n,v,x,y,w));
    }
    if(min_dis == INF) cout << -1;
    else cout << min_dis;
    return 0;
}
/*
5 6
1 2 10 0
2 3 10 0
1 3 5 1
3 4 10 0
4 5 10 0
3 5 4 1

5 4
1 2 10 0
2 3 10 1
3 4 10 0
4 5 10 1
 */
