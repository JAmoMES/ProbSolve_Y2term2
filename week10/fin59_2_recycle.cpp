#include <iostream>

using namespace std;

#define MxN 100000

pair<int,int> dp[MxN+1];
pair<int,int> house[MxN+1];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> house[i].first >> house[i].second ;
    }
    dp[0] = {0,0};
    house[0] = {0,0};
    for (int i = 1; i <= n; i++) {
        pair<int,int> p = {1<<30,0};
        for (int j = i-10; j < i; j++) {
            if (j < 0) continue;
            if (dp[j].first <= p.first && dp[j].second + house[i].second >= i-1){
                p = dp[j];
//                cout << p.first << ',' << p.second << ' ';
            }
            dp[i].first = p.first + house[i].first;
            dp[i].second = i + house[i].second;
//            cout << '(' << dp[i].first << ' ' << dp[i].second << ')' << '\n';
        }
    }
    int minn = 1<<30;
    for (int i = n; i > 0; i--) {
        if (dp[i].second >= n)
            minn = min(minn,dp[i].first);
    }
    cout << minn;
    return 0;
}