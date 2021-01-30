#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char a[60][60];
int level[2500][60][60];

int bfs(pair<int,int> start,pair<int,int> stop,int times){
    queue<pair<int,int>> q;
    q.push(start);
    while(!q.empty()){
        pair<int,int> x = q.front();
        q.pop();
        if(level[times][x.first-1][x.second]==0&& a[x.first-1][x.second] == '.' ){
            level[times][x.first-1][x.second] = level[times][x.first][x.second]+1;
            q.push({x.first-1,x.second});
        }
        if(level[times][x.first+1][x.second]==0 && a[x.first+1][x.second] == '.' ){
            level[times][x.first+1][x.second] = level[times][x.first][x.second]+1;
            q.push({x.first+1,x.second});
        }
        if(level[times][x.first][x.second-1]==0 && a[x.first][x.second-1] == '.' ){
            level[times][x.first][x.second-1] = level[times][x.first][x.second]+1;
            q.push({x.first,x.second-1});
        }
        if(level[times][x.first][x.second+1]==0 && a[x.first][x.second+1] == '.'){
            level[times][x.first][x.second+1] = level[times][x.first][x.second]+1;
            q.push({x.first,x.second+1});
        }
    }
    if (level[times][stop.first][stop.second]) return level[times][stop.first][stop.second];
    return -1;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    pair <int,int> start ,stop;
    cin >> start.first >> start.second >> stop.first >> stop.second;
    for(int i=0;i<=n+1;i++){
        a[i][0] = '#';
        a[i][m+1] = '#';
    }
    for(int i=0;i<=m+1;i++){
        a[0][i] = '#';
        a[n+1][i] = '#';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == '*')
                v.emplace_back(i,j);
        }
    }
//    for(int i=0;i<=n+1;i++){
//        for(int j=0;j<=m+1;j++){
//            cout << a[i][j];
//        }
//        cout << '\n';
//    }
    int t = 0;
    int minn = bfs(start,stop,t++);
    for(auto it:v){
        a[it.first][it.second] = '.';
        int x = bfs(start,stop,t++);
        if(x!=-1) minn = min(minn,x);
        a[it.first][it.second] = '*';
    }
    cout << minn;
    return 0;
}


/*
6 5
2 2 5 4
#####
#...#
#.###
#*..#
###.#
#####
 */
