#include <iostream>
#include <queue>
#include <list>
using namespace std;

bool can_jump(pair<int,int> pos1,pair<int,int> pos2,int r){
    int x_pow2 = (pos2.first-pos1.first)*(pos2.first-pos1.first);
    int y_pow2 = (pos2.second-pos1.second)*(pos2.second-pos1.second);
    return x_pow2 + y_pow2 <= r*r;
}

int bfs(list<int> *graph_pos,int n){
    queue<int> q;
    q.push(0);
    bool visited[n];
    int level[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    visited[0] = true;
    level[0] = 0;
    level[n-1] = -1;
    q.push(0);
//    cout << 0 << "\n";
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto it:graph_pos[x]) {
            if(visited[it] == 0){
                visited[it] = true;
                q.push(it);
                level[it] = level[x] + 1;
//                if(it == n-1)
//                    break;
//                for(int i=0;i<level[it];i++)
//                    cout << "   ";
//                cout << it << "\n";
            }
        }
    }
    return level[n-1];
}

int main(){
    int n,r;
    cin >> n >> r;
    pair<int,int> pos[n+2];
    pos[0] = make_pair(0,0);
    pos[n+1] = make_pair(100,100);
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        pos[i] = make_pair(x,y);
    }
    list<int> graph_pos[n+2];
    for(int i=0;i<=n+1;i++){
        for(int j=i;j<=n+1;j++){
            if(can_jump(pos[i],pos[j],r)&& i!=j){
                graph_pos[i].push_back(j);
                graph_pos[j].push_back(i);
            }
        }
    }
//    for(int i=0;i<=n+1;i++){
//        cout << i << ": ";
//        for(auto it:graph_pos[i]){
//            cout << it << " ";
//        }
//        cout << "\n";
//    }
    cout << bfs(graph_pos,n+2);
    return 0;
}
