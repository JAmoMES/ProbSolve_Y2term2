#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[100001];
bool visited_magic[100001];
bool type[100001];
vector<pair<int,int>> v[100001];

void bfs(int s,int h){
    queue<pair<int,int>> q;
    if(type[s]) visited_magic[s] = true;
    else visited[s] = true;
    q.push({s,0});
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(x.second == h) return;
        for(auto it:v[x.first]) {
            if(!visited[it.first]&&type[x.first]== false){
                if(it.second == 1)continue;
                visited[it.first] = true;
                q.push({it.first,x.second + 1});
            }
            else if(!visited_magic[it.first]&&type[x.first] == true){
                type[it.first] = true;
                visited_magic[it.first] = true;
                q.push({it.first,x.second + 1});
            }
        }
    }
}

int main(){
    int n,m,c,h;
    cin >> n >> m >> c >> h;
    for(int i=0;i<c;i++){
        int x;
        cin >> x;
        type[x] = true;
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        v[x].emplace_back(y,z);
        v[y].emplace_back(x,z);
    }
    bfs(1,h);
    int count = 0;
//    for(int i=1;i<n+1;i++){
//        cout << visited[i] << " ";
//    }
//    cout << "\n";
//    for(int i=1;i<n+1;i++){
//        cout << visited_magic[i] << " ";
//    }
//    cout << "\n";
    for(int i=1;i<n+1;i++){
//        cout << dis[i] << " " ;
        if(visited[i] || visited_magic[i]) count++;
    }
    cout << count ;
    return 0;
}

/*
6 5 0 2
1 2 0
3 2 0
4 1 0
4 5 0
5 6 0

7 7 1 3
2
1 2 0
7 1 1
1 3 0
3 4 0
4 5 0
6 5 0
3 6 1
*/