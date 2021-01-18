#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while(k--) {
        int n, m;
        cin >> n >> m;
        vector<int> v[n+1];
        for (int i = 0; i < m; i++) {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int color[100001] = {0};
        queue<int> q;
        q.push(1);
        color[1] = 1;
        bool ans = true;
        int size = 1, start =1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int y;
            if(color[x] == 1) y=2;
            else y=1;
            for(unsigned int i=0 ; i < v[x].size() ; i++){
                if(color[v[x][i]] == 0){
                    color[v[x][i]] = y;
                    q.push(v[x][i]);
                    size++;
                }
                else{
                    if(color[x] == color[v[x][i]]){
                        ans = false;
                        break;
                    }
                }
            }
            if(q.empty() && size != n){
                for(;start<=n;start++)
                    if(color[start] == 0){
                        q.push(start);
                        color[start] = 1;
                        size++;
                        break;
                    }
            }
            if(!ans) break;
        }
        cout << (ans? "yes":"no") << "\n";
    }
    return 0;
}