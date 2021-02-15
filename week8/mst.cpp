#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define INF 100000

int dis[100001];
bool visited[100001];

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v[n+1];
    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }
    for (int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    dis[1] = 0;
    while(!q.empty()){
        auto x = q.top();
        int node = x.second;
        q.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(auto it:v[node]){
            if(!visited[it.first]&&dis[it.first] > it.second) {
                dis[it.first] = it.second;
                q.push({it.second ,it.first});
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
//        cout << dis[i] << " ";
        sum += dis[i];
    }
//    cout << "\n";
    cout << sum;
    return 0;
}