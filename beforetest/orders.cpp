#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[100001];
vector<int> v[100001];

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m ;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        if(visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = i;
        while(!q.empty()){
            int x =q.front();
            q.pop();
            for(int it : v[x]){
                if(visited[it]) continue;
                q.push(it);
                visited[it] = i;
            }
        }
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        cout << (visited[a] == visited[b]? 1:0) << "\n";
    }
    return 0;
}