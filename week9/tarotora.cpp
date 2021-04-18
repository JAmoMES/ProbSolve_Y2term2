#include <iostream>
using namespace std;

int a[100000];
int b[100000];

int lowest(int n,int k){
    int dp[n+1][n+1];
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            dp[i][j] = 0;
        }
    }
    int ans = 1<<30;
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i+j > n || abs(i-j) >k) {
                dp[i][j]=1<<30;
                continue;
            }
            if(i == 0 && j == 0){
                dp[0][0] = 0;
            }
            else if(i == 0){
                dp[i][j] = dp[i][j-1]+b[i+j];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][j]+a[i+j];
            }
            else{
                dp[i][j] = min(dp[i][j-1]+b[i+j], dp[i-1][j]+a[i+j]);
            }
//            cout  << "i: " << i << "j: " << j << " value: " << dp[i][j] << "  ";
            if(i+j == n){
                ans = min(ans, dp[i][j]);
            }
        }
//        cout << "\n";
    }
    return ans;
}

int main() {
    int loop;
    int n, k;
    cin >> loop;
    for (int i = 0; i < loop; ++i) {
        cin >> n >> k;
        for (int j = 1; j < n+1; ++j) {
            cin >> a[j] >> b[j];
        }
        cout << lowest(n,k) << "\n";
    }
}