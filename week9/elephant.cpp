#include <iostream>

using namespace std;

#define MxN 100000

int banana[MxN];
int dp[MxN];

int point(int start,int stop){
    if (start >= stop)
        return 0;
    if (dp[start]!=-1)
        return dp[start];
    return dp[start] = max(banana[start]+point(start+3,stop),point(start+1,stop));
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> banana[i];
        dp[i] = -1;
    }
    cout << point(2,n);
    return 0;
}

