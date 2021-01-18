#include <iostream>
#include <queue>
#include <set>
#include <list>
using namespace std;

int in_order[100001];

int main(){
    int n,m;
    cin >> n >> m;
    set<int> no_inorder;
    for(int i=0;i<n;i++){
        no_inorder.insert(i+1);
    }
    vector<int> v[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        in_order[y]++;
        no_inorder.erase(y);
    }
    queue<int> q;
    for(auto it: no_inorder)
        q.push(it);
    list<int> topological;
    while(!q.empty()){
        int x =q.front();
        q.pop();
        topological.push_back(x);
        for(auto it:v[x]){
            in_order[it]--;
            if(in_order[it]==0)
                q.push(it);
        }
    }
    if(topological.size() == n){
        for(auto it:topological)
            cout << it << "\n";
    }
    else cout << "no";
    return 0;
}

