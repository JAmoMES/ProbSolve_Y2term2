#include <iostream>
#include <unordered_set>
using namespace std;

char map[121][121];
int parent[243];
int walked_map[2][121][121] = {0};
int success = 241,fail = 242;

int find_parent(int x){
    if(parent[x]>240) return parent[x];
    return find_parent(parent[x]);
}

void walk(int w,int i,int j,bool direct,int start){
    if(walked_map[direct][i][j] && walked_map[direct][i][j]!=start){
        parent[start] = walked_map[direct][i][j];
        return;
    }
    walked_map[direct][i][j] = start;
    if(map[i][j] == '.') i++;
    else if(!direct && j != 0) j--;
    else if(direct && j != w-1) j++;
    else direct = !direct;
    walk(w,i,j,direct,start);
}

int find_new_parent(int w,int i,int j,bool direct,int start){
    if(walked_map[direct][i][j]) return find_parent(walked_map[direct][i][j]);
    if(map[i][j] == '.') i++;
    else if(!direct && j != 0) j--;
    else if(direct && j != w-1) j++;
    else direct = !direct;
    return find_new_parent(w,i,j,direct,start);
}

bool is_success(int x,unordered_set<int> &can,unordered_set<int> &cant){
    if(can.find(x) != can.end()) return true;
    if(cant.find(x) != cant.end()) return false;
    if(parent[x] == success){
        can.insert(x); return true;
    }
    if(parent[x] == fail){
        cant.insert(x); return false;
    }
    bool result = is_success(parent[x],can,cant);
    if(result) can.insert(x);
    else cant.insert(x);
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    parent[241] = 241;
    parent[242] = 242;
    int w,h;
    cin >> w >> h;
    for(int i=0;i<h-1;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
        }
    }
    for(int j=0;j<w;j++){
        cin >> map[h-1][j];
        if(map[h-1][j] == '$'){
            walked_map[0][h-1][j] = 241;
            walked_map[1][h-1][j] = 241;
        }
        else if(map[h-1][j] == '@'){
            walked_map[0][h-1][j] = 242;
            walked_map[1][h-1][j] = 242;
        }
        walked_map[0][h][j] = 242;
        walked_map[1][h][j] = 242;
    }
    for(int i=0;i < w ;i++){
        walked_map[0][0][i] = i+1;
        walked_map[1][0][i] = i+w+1;
    }
    for(int i=0;i < w ;i++){
        walk(w,0,i,false,i+1);
        walk(w,0,i,true,i+w+1);
    }
    int money;
    unordered_set<int> can;
    unordered_set<int> cant;
    for(int i = 0;i < 2*w ;i++){
        is_success(i+1,can,cant);
    }
    money =can.size();
    cout << money << " ";
    for(int i=0;i<h-1;i++){
        for(int j=0;j<w;j++) {
            if (map[i][j] == '.') continue;
            else if(walked_map[0][i][j]==0 && walked_map[1][i][j]==0) continue;
            int old_parentA = parent[walked_map[0][i][j]];
            int old_parentB = parent[walked_map[1][i][j]];
            if(walked_map[0][i][j]) {
                parent[walked_map[0][i][j]] = find_new_parent(w, i + 1, j, false,walked_map[0][i][j]);
            }
            if(walked_map[1][i][j]) {
                parent[walked_map[1][i][j]] = find_new_parent(w, i + 1, j, true,walked_map[1][i][j]);
            }
            unordered_set<int> can2;
            unordered_set<int> cant2;
            for (int k = 0; k < 2 * w; k++) {
                is_success(k + 1, can2, cant2);
            }
            int new_money = can2.size();
            money = max(new_money, money);
            parent[walked_map[0][i][j]] = old_parentA;
            parent[walked_map[1][i][j]] = old_parentB;
        }
    }
    cout << money;
    return 0;
}
