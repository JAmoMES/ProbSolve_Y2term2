#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000

//typedef pair<int,pair<int,int>> tri;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int distance[n+1];
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
    for(int i=1;i<n+1;i++){
        distance[i] = INF;
    }
    vector<pair<int,int> > v[n+1];
    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
    }
    distance[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        auto x = q.top();
        int now = x.second;
        q.pop();
        for(auto it:v[x.second]){
            int dis = distance[it.first];
            int next = it.first;
            int w = it.second;
            if(distance[next] > distance[now] + w)
                distance[next] = distance[now] + w;
            if(dis==INF)
                q.push({distance[next],next});
        }
    }
    cout << distance[n];
    return 0;
}
/*
4 5
1 2 10
1 3 20
3 4 5
4 2 7
2 3 12
 */
