#include <iostream>

using namespace std;

#define MxN 100000

int profit[MxN+1][2];
int dp[MxN+1][3];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i][0] >> profit[i][1];
    }
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][1]+profit[i][0],dp[i-1][2]+profit[i][0]);
        dp[i][1] = max(dp[i-1][0]+profit[i][1],dp[i-1][2]+profit[i][1]);
        dp[i][2] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
    }
    cout << max(dp[n][0],max(dp[n][1],dp[n][2]));
    return 0;
}