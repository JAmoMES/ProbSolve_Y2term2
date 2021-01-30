#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
//    for(int i=1;i<=n;i++){
//        cout << i << ": ";
//        for(auto it:v[i]){
//            cout << it << " ";
//        }
//        cout << '\n' ;
//    }
    int visited[1001] = {0};
    int a=0,b=0;
    for(int i=1;i<=n;i++){
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it:v[x]){
                if(visited[it]){
                    if(visited[x] == visited[it]) {
                        a = x;
                        b = it;
                        break;
                    }
                }
                else {
                    visited[it] = visited[x]%2+1;
                    q.push(it);
                }
            }
        }
        if(a&&b) break;
    }
//    for(int i=1; i<=n ;i++)
//        cout << visited[i] << " ";
//    cout << '\n';
    cout << a << " " << b;
    return 0;
}
