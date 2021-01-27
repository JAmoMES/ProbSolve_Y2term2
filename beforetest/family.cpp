#include <iostream>
using namespace std;

int parent[1001];

int find(int parent_t,int child){
    if(!parent[child]) return -1;
    if(parent[child] == parent_t) return parent_t;
    return find(parent_t,parent[child]);
}

int main(){
    int n,m;
    cin >> n >> m;
    parent[1] = 0;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        parent[i] = x;
    }
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        int a = find(y,x);
        int b = find(x,y);
        cout << max(a,b);
        cout << '\n';
    }
    return 0;
}

