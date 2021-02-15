#include <iostream>

using namespace std;

int parent[100001];

int find_parent(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        parent[i+1] = i+1;
    }
    for(int i =0;i<m;i++){
        char command;
        cin >> command;
        int x,y;
        switch (command) {
            case 'c':
                cin >> x >> y;
                parent[find_parent(x)] = find_parent(y);
                break;
            case 'q':
                cin >> x >> y;
                if(find_parent(x) == find_parent(y))
                    cout << "yes\n";
                else cout << "no\n";
        }
    }
    return 0;
}