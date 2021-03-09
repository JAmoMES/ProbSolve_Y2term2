#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MxN 20000

queue<pair<int,int>> concrete,com;
vector<int> adj[MxN+1];
vector<pair<pair<int,int>,int>> ans;
int par1[MxN+1];
int par2[MxN+1];

void dfs(int now,int par){
    par1[now] = par;
    for(int it:adj[now])
        if(!par1[it])
            dfs(it,par);
}

int union_f1(int x){
    if (par1[x] == x) return x;
    return par1[x] = union_f1(par1[x]);
}

int union_f2(int x){
    if (par2[x] == x) return x;
    return par2[x] = union_f2(par2[x]);
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        int x,y,w;
        cin >> x >> y >> w;
        if(w == 0)
            concrete.push({x,y});
        else{
            adj[x].push_back(y);
            adj[y].push_back(x);
            com.push({x,y});
        }
    }
    for(int i=1;i<=n;i++){
        par2[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(!par1[i]){
            dfs(i,i);
        }
    }
    queue<pair<int,int>> q;
    while(!concrete.empty()){
        int x = concrete.front().first;
        int y = concrete.front().second;
        concrete.pop();
        if(union_f1(x)!=union_f1(y)){
            ans.push_back({{x,y},0});
            par1[union_f1(x)] = union_f1(y);
            par2[union_f2(x)] = union_f2(y);
        }
        else {
            q.push({x,y});
        }
    }
//    cout << q.size() << ans.size() << k;
    while(!q.empty() && ans.size() < k){
        int x = q.front().first;
        int y = q.front().second;
        if(union_f2(x)!=union_f2(y)) {
            ans.push_back({q.front(), 0});
            par2[union_f2(x)] = union_f2(y);
        }
        q.pop();
    }
    if (ans.size()!=k){
        cout << "no solution" << '\n';
        return 0;
    }
    while(!com.empty()){
        int x = com.front().first;
        int y = com.front().second;
        if(union_f2(x)!=union_f2(y)) {
            ans.push_back({com.front(), 1});
            par2[union_f2(x)] = union_f2(y);
        }
        com.pop();
    }
    if(ans.size()!=n-1)
        cout << "no solution" << '\n';
    else{
        for(auto it:ans){
            cout << it.first.first << " " << it.first.second << " " << it.second << '\n';
        }
    }
    return 0;
}