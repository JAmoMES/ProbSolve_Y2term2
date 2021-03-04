#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

vector<int> bridge[50001][2];
int level[50001][2];

int bfs(int color,int s,int t){
    queue<int> q;
    level[s][color] = 0;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto it:bridge[x][color]) {
            if(level[it][color] == 0){
                level[it][color] = level[x][color] + 1;
                q.push(it);
            }
        }
    }
    //cout << "distance : "<< level[t][color] << "\n";
    if (level[t][color] == 0) return 100000;
    return level[t][color];
}


int main() {
    int n, m, start, stop;
    cin >> n >> m >> start >> stop;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0 || c == 1) {
            bridge[a][0].push_back(b);
            bridge[b][0].push_back(a);
        }
        if (c == 0 || c == 2) {
            bridge[a][1].push_back(b);
            bridge[b][1].push_back(a);
        }
    }
    int color = 0;
    int minn = min(bfs(color++, start, stop), bfs(color++, start, stop));
//    for(int i =1;i<=n;i++){
//        cout << level[i][0] << " ";
//    }
//    cout << "\n";
//    for(int i =1;i<=n;i++){
//        cout << level[i][1] << " ";
//    }
//    cout << "\n";
    if (minn != 100000) cout << minn << '\n';
    else cout << -1 << "\n";
    return 0;
}
/*
6 7 2 4
2 5 0
3 4 2
6 5 0
3 6 0
1 4 1
2 1 2
1 3 0

3 2 1 3
1 2 1
2 3 2

*/
