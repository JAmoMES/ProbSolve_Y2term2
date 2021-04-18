#include <iostream>

using namespace std;

#define MxN 20

char map[MxN+1][MxN+1];
int dp[MxN+2][MxN+2][4];
int ans[4*MxN+1];
int n;

int gogo(int i,int j,int di){
//    cout << i << ',' << j << ' ' << di << '\n';
    if (dp[i][j][di] != 0)
        return dp[i][j][di];
    int d = di;
    if ((map[i][j] == '\\' && di%2==0) ||\
        (map[i][j] == '/' && di%2==1)) {
        di = (di+3)%4;
    }
    else if ((map[i][j] == '\\' && di%2==1) ||\
            (map[i][j] == '/' && di%2==0)) {
        di = (di+1)%4;
    }
    if (di==0)
        return dp[i][j][d] = gogo(i-1,j,di);
    if (di==1)
        return dp[i][j][d] = gogo(i,j+1,di);
    if (di==2)
        return dp[i][j][d] = gogo(i+1,j,di);
    if (di==3)
        return dp[i][j][d] = gogo(i,j-1,di);
}


int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    for (int i=1;i<n+1;i++){
        dp[i][0][3] = i;
        dp[n+1][i][2] = i+n;
        dp[n-i+1][n+1][1] = i+2*n;
        dp[0][n-i+1][0] = i+3*n;

//        cout << i << '(' << i << ',' << 1 << ")\n";
//        cout << i+n << '(' << n << ',' << i << ")\n";
//        cout << i+2*n << '(' << n-i+1 << ',' << n << ")\n";
//        cout << i+3*n << '(' << 1 << ',' << n-i+1 << ")\n";
    }

    for (int i=1;i<n+1;i++){
        ans[i] = gogo(i,1,1);
        ans[i+n] = gogo(n,i,0);
        ans[i+2*n] = gogo(n-i+1,n,3);
        ans[i+3*n] = gogo(1,n-i+1,2);
    }
    for (int i=1;i<4*n+1;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
