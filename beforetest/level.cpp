#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[3][101];
    for(int i=1;i<=n-1;i++){
        int x,y,z;
        cin >> x >> y >> z;
        a[0][i] = x;
        a[1][i] = y;
        a[2][i] = z;
    }
    int stage = 1;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(stage == n) continue;
        if(a[0][stage] <= x) a[0][stage] = 0;
        if(a[1][stage] <= y) a[1][stage] = 0;
        if(a[2][stage] <= z) a[2][stage] = 0;
        if(a[0][stage]+a[1][stage]+a[2][stage] == 0)
            stage++;
    }
    cout << stage;
    return 0;
}
