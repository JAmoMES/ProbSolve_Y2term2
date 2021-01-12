#include <iostream>
#include <set>
using namespace std;

char map[30][30];

void dfs(pair<int,int> p,int &area,bool &quality1,bool &quality2,set<pair<int,int>> &not_go){
    //cout << map[p.first][p.second] << "(" << p.first << "," << p.second <<")\n";
    if(map[p.first][p.second] == '#') return;
    else if(map[p.first][p.second] == '*') quality1 = true;
    else if(map[p.first][p.second] == '$') quality2 = true;
    area++;
    if(not_go.find(make_pair(p.first-1,p.second))!=not_go.end()){
        not_go.erase(make_pair(p.first-1,p.second));
        dfs(make_pair(p.first-1,p.second),area,quality1,quality2,not_go);
    }
    if(not_go.find(make_pair(p.first+1,p.second))!=not_go.end()){
        not_go.erase(make_pair(p.first+1,p.second));
        dfs(make_pair(p.first+1,p.second),area,quality1,quality2,not_go);
    }
    if(not_go.find(make_pair(p.first,p.second-1))!=not_go.end()){
        not_go.erase(make_pair(p.first,p.second-1));
        dfs(make_pair(p.first,p.second-1),area,quality1,quality2,not_go);
    }
    if(not_go.find(make_pair(p.first,p.second+1))!=not_go.end()){
        not_go.erase(make_pair(p.first,p.second+1));
        dfs(make_pair(p.first,p.second+1),area,quality1,quality2,not_go);
    }

}

int main(){
    int n,m;
    cin >> n >> m;
    set<pair<int,int>> not_go;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            not_go.insert(make_pair(i,j));

        }
    }
    int good_quality = 0,high_quality = 0;
    while(!not_go.empty()){
        //cout << "new land!\n";
        int area=0;
        bool quality1=false,quality2=false;
        auto p = not_go.begin();
        not_go.erase(p);
        dfs(*p,area,quality1,quality2,not_go);
        if(quality1 & quality2) high_quality += area;
        else if(quality1 | quality2) good_quality +=area;
    }
    cout << high_quality << " " << good_quality;
    return 0;
}