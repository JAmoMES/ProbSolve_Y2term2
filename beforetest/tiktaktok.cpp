#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> path;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        path.emplace_back(a,b);
    }
//    for(int i=1;i<=n;i++){
//        cout << i << ": ";
//        for(auto it:v[i]){
//            cout << it << " ";
//        }
//        cout << '\n' ;
//    }
    pair<int,int> ans;
    for(auto it1:path) {
        int visited[1001] = {0};
        bool bipartite = true;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (auto it:v[x]) {
                    if((x ==  it1.first && it == it1.second)||(x ==  it1.second && it == it1.first)) continue;
                    if (visited[it]) {
                        if (visited[x] == visited[it]) {
                            bipartite = false;
                            break;
                        }
                    } else {
                        visited[it] = visited[x] % 2 + 1;
                        q.push(it);
                    }
                }
            }
        }
        if(bipartite == true){
            ans = it1;
            break;
        }
    }
//    for(int i=1; i<=n ;i++)
//        cout << visited[i] << " ";
//    cout << '\n';
    cout << ans.first << " " << ans.second ;
    return 0;
}