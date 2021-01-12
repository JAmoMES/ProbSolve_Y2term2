#include <iostream>
#include <set>
using namespace std;

bool can_go[29][29];

void dfs(bool &success,pair<int,int> p,int stop){
    //cout << can_go[p.first][p.second] << "(" << p.first << "," << p.second <<")\n";
    if(p.first == stop) {
        success = true;
        return;
    }
    can_go[p.first][p.second] = false;
    if(!success && can_go[p.first - 1][p.second])
        dfs(success,make_pair(p.first-1,p.second),stop);
    if(!success && can_go[p.first + 1][p.second])
        dfs(success,make_pair(p.first+1,p.second),stop);
    if(!success && can_go[p.first][p.second - 1])
        dfs(success,make_pair(p.first,p.second-1),stop);
    if(!success && can_go[p.first][p.second + 1])
        dfs(success,make_pair(p.first,p.second+1),stop);
}

int main(){
    int n,m;
    bool success = false;
    cin >> n >> m;
    char area[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> area[i][j];
        }
    }
    set<pair<int,int>> start;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(area[i][j]!='#'&&area[i+1][j]!='#'&&area[i][j+1]!='#'&&area[i+1][j+1]!='#')
                can_go[i][j] = true;
            else can_go[i][j] = false;
            if (i==0 && can_go[i][j])
                start.insert(make_pair(i,j));
        }
    }
    while(!start.empty()){
        //cout << "start\n";
        auto it = start.begin();
        start.erase(it);
        dfs(success,*it,n-2);
        if(success) break;
    }
    cout << (success? "yes":"no");
    return 0;
}

