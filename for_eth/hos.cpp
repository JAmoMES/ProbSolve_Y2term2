#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 2000001

vector<int> house[100001];
int safe[100001];

void bfs(int s,int h,int growth){
    queue<int> q;
    safe[s] = 0;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        if (safe[x] + growth > h) return;
        q.pop();
        for(auto it:house[x]) {
            if(safe[it] > safe[x] + growth){
                safe[it] = safe[x] + growth;
                q.push(it);
            }
        }
    }
}

int main(){
    int n,m,k,h;
    cin >> n >> m >> k >> h;
    vector<int> small;
    vector<int> big;
    for(int i=1;i<n+1;i++) {
        safe[i] = INF;
    }
    int a[k];
    for(int i=0;i<k;i++) {
        cin >> a[i];
    }
    for(int i=0;i<k;i++) {
        int type;
        cin >> type;
        if(type) big.push_back(a[i]);
        else small.push_back(a[i]);
    }
    for(int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        house[x].push_back(y);
        house[y].push_back(x);
    }
    //cout << "big: ";
    for(int it:big){
        //cout << it << " ";
        bfs(it,h*2,1);
    }
    //cout << "\nsmall :";
    for(int it:small){
        //cout << it << " ";
        bfs(it,h*2,2);
    }
    //cout << "\n";
    int count =0;
    for(int i=1;i <= n;i++){
        //cout << safe[i] << " ";
        if(safe[i]!=INF) count++;
    }
    //cout << "\n";
    cout << count;
    return 0;
}
/*
7 6 1 2
2
0
1 2
2 3
3 4
4 5
5 6
6 7

7 7 2 1
4 2
0 1
1 2
7 1
1 3
3 4
4 5
6 5
3 6

10 9 2 2
9 1
1 0
1 2
2 3
3 4
5 4
5 6
6 7
7 8
9 8
9 10
*/