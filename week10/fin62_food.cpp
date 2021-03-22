#include <iostream>
using namespace std;

#define MxN 5000
#define INF 1<<30

int people[MxN+1];
int dp[MxN+1][MxN+1];
int n,k;

int min_loss(int i,int w){
//    if (i==0)
//        return dp[i][w] = 0;
    if (dp[i][w] != INF)
        return dp[i][w];
    if (w < people[i])
        return dp[i][w] = min_loss(i-1,k) + people[i];
    return dp[i][w] = min(min_loss(i-1,w-people[i]),min_loss(i-1,k) + people[i]);
}

int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> people[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = INF;
        }
    }
    cout << min_loss(n,k);
    return 0;
}
