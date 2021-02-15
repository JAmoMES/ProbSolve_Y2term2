#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;

int cost[100001];

typedef pair<int,pair<int,int>> tri;

void dijkstra(int n,vector<pair<int,int> > v[]){
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
    for(int i=1;i<n+1;i++){
        cost[i] = INF;
    }
    cost[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        auto x = q.top();
        int now = x.second;
        q.pop();
        if(cost[now] < x.first) continue;
        for(auto it:v[x.second]){
            int next = it.first;
            int w = it.second;
            if(cost[next] > cost[now] + w) {
                cost[next] = cost[now] + w;
                q.push({cost[next], next});
            }
        }
    }
}

int main(){
    int n,m,l;
    cin >> n >> m >> l;
    int people[n+1];
    for(int i=1;i<=n;i++){
        cin >> people[i];
    }
    vector<pair<int,int> > v[n+1];
    for(int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
    }
    dijkstra(n,v);
    int sum = 0;
    for(int i=1;i<=n;i++){
        int best = min(people[i]*cost[i],l*cost[i]);
        sum += best;
    }
    cout << sum ;
    return 0;
}
/*
4 5 4
0 1 2 7
1 2 5
3 1 14
2 3 7
4 2 11
1 4 15
 */
