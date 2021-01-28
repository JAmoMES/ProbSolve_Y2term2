#include <iostream>
using namespace std;

int visited[23][23];
int map[23][23];

void make_wall(int n){
    for(int i=0;i<=n+1;i++){
        map[0][i] = 2000001;
        map[n+1][i] = 2000001;
        map[i][0] = 2000001;
        map[i][n+1] = 2000001;
    }
}

int dfs(int i,int j,int stop_i,int stop_j,int k){
    //cout << i << " " << j << " " << map[i][j] << '\n';
    if(i == stop_i && j == stop_j) return 1;
    if(!visited[i-1][j] && map[i][j] + k >= map[i-1][j]) {
        visited[i-1][j] = 1;
        if (dfs(i - 1, j, stop_i, stop_j, k)) return 1;
    }
    if(!visited[i+1][j] && map[i][j] + k >= map[i+1][j]) {
        visited[i+1][j] = 1;
        if (dfs(i + 1, j, stop_i, stop_j, k)) return 1;
    }
    if(!visited[i][j-1] && map[i][j] + k >= map[i][j-1]) {
        visited[i][j-1] = 1;
        if (dfs(i , j-1, stop_i, stop_j, k)) return 1;
    }
    if(!visited[i][j+1] && map[i][j] + k >= map[i][j+1]) {
        visited[i][j+1] = 1;
        if (dfs(i , j+1, stop_i, stop_j, k)) return 1;
    }
    return 0;
}

int main(){
    int n,k;
    cin >> n >> k;
    make_wall(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
        }
    }
    visited[1][1] = 1;
    cout << (dfs(1,1,n,n,k)? "yes":"no");
    return 0;
}
