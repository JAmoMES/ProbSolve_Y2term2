#include <iostream>
#include <vector>
#include <set>
using namespace std;

char maze[22][22];
int visited[401][22][22];
int times = 0;
int color = 1;

void dfs(int i,int j){
    if(maze[i][j] == '#' || maze[i][j] == 'O') {
        visited[times][i][j] = -1;
        return;
    }
    visited[times][i][j] = color;
    if(!visited[times][i-1][j]){
        dfs(i-1,j);
    }
    if(!visited[times][i+1][j]){
        dfs(i+1,j);
    }
    if(!visited[times][i][j-1]){
        dfs(i,j-1);
    }
    if(!visited[times][i][j+1]){
        dfs(i,j+1);
    }
}

void print_visited(int n){
    for(int i=1;i<=n;i++) {
        for (int j = 1; j<= n; j++) {
            if(visited[times][i][j]>0)
                cout << visited[times][i][j] << " ";
            else cout << "# ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i=0;i<=n+1;i++){
        maze[0][i] = '#';
        maze[n+1][i] = '#';
        maze[i][0] = '#';
        maze[i][n+1] = '#';
    }
    vector<pair<int,int>> gate;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j<= n; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'O')
                gate.emplace_back(i,j);
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j<= n; j++) {
            if(visited[times][i][j] != 0)
                continue;
            dfs(i,j);
            color++;
        }
    }
    //print_visited(n);
    times++;
    for(auto it:gate){
        set<pair<int,int>> connect;
        maze[it.first][it.second] = '.';
        dfs(it.first,it.second);
        maze[it.first][it.second] = 'O';
        color++;
        //print_visited(n);
        times++;
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        bool go = false;
        for(int j =0;j < times;j++){
            if(visited[j][a][b] == visited[j][c][d] && visited[j][a][b] > 0){
                go = true;
                break;
            }
        }
        cout << (go? "yes":"no") << "\n";
    }
    return 0;
}
/*
6 2
...#.#
.###.#
......
####.#
..#..#
...#..
1 3 5 5
1 5 5 1

7 4
#.#....
..#####
#......
#.#O###
#.#..#.
#.##O##
#.#....
2 1 3 7
2 1 5 4
2 1 1 6
2 1 7 6
*/