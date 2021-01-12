#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int bfs(int start,map<int,vector<int>> &graph,int ttl){
    set<int> visited;
    queue<int> q;
    map<int,int> level;
    level[start] = 0;
    q.push(start);
    visited.insert(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto it:graph[x]){
            if(visited.find(it) == visited.end()) {
                level[it] = level[x] + 1;
                if(level[it] <= ttl){
                    q.push(it);
                    visited.insert(it);
                }
            }
        }
    }
    return graph.size() - visited.size();
}

int main(){
    int nc,num = 1;
    while(cin >> nc,nc){
        map<int,vector<int>> graph;
        int x,y;
        for(int i = 0;i<nc;i++){
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int start,ttl;
        while(cin >> start >> ttl ,start && ttl){
            int miss = bfs(start,graph,ttl);
            cout << "Case " << num++ << ": " << miss << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n";
        }
    }
    return 0;
}
/*
16
10 15
15 20
20 25
10 30
30 47
47 50
25 45
45 65
15 35
35 55
20 40
50 55
35 40
55 60
40 60
60 65
35 2
 */
