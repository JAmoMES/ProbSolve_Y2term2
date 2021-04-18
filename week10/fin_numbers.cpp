#include <iostream>

using namespace std;

#define MxN 100000

int a[MxN+1],b[MxN+1];
int dp[MxN+1];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0;
    b[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (a[i]>0) b[i]=1;
    }
    for (int i = 1; i <= n; i++){
        int x = 1<<31;
        for (int j = i-4;j<i;j++){
//            cout << j << ',';
            if (j<0) continue;
            if (b[j] == 1)
                x = dp[j];
            else{
                x = max(x,dp[j]);
            }
//            cout << x << ' ';
        }
        dp[i] = x+a[i];
//        cout << dp[i] << '\n';
    }
    int maxx = 1<<31;
    for (int i = n-3; i <= n ; ++i) {
        if (b[i] == 1)
            maxx = dp[i];
        else{
            maxx = max(maxx,dp[i]);
        }
    }
    cout << maxx;
    return 0;
}

