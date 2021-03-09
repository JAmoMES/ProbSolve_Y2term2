#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 100000

vector<pair<int,int>> v[201];
bool visited[6000][201];
int dis[201];

int mst(int start,int week){
    for(int i=1;i<=200;i++){
        dis[i] = INF;
    }
    int sum = 0;
    int count = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    dis[start] = 0;
    while(!q.empty()){
        auto x = q.top();
        int node = x.second;
        q.pop();
        if(visited[week][node]) continue;
        count++;
        visited[week][node] = true;
        sum += dis[node];
        for(auto it:v[node]){
            if(!visited[week][it.first]&&dis[it.first] > it.second) {
                dis[it.first] = it.second;
                q.push({it.second ,it.first});
            }
        }
    }
    if (start == count) return sum;
    return -1;
}

int main(){
    int n,w;
    cin >> n >> w;
    for(int i=0;i<w;i++){
        int x,y,w;
        cin >> x >> y >> w;
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
        cout << mst(n,i) << '\n';
    }
    return 0;
}