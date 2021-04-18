#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MxN 1000

int n,m,h;
vector<int> adj[MxN+1];
bool visited[MxN+1][MxN+1];
int layer[MxN+1][MxN+1];

int bfs(int i){
    queue<int> q;
    q.push(i);
    visited[i][i] = true;
    layer[i][i] = 0;
    int count = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if (layer[x][i] > h)
            break;
        count++;
        for(int it:adj[x]){
            if (visited[it][i])
                continue;
            q.push(it);
            visited[it][i] = true;
            layer[it][i] = layer[x][i] + 1;
        }
    }
    return count;
}

int main(){
    cin >> n >> m >> h;
    int maxx=0;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i =1;i<=n;i++){
        maxx = max(maxx,bfs(i));
    }
    cout << maxx;
    return 0;
}