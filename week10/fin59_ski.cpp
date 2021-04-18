#include <iostream>

using namespace std;

#define MxN 1000

pair<int,int> a[MxN+1];
pair<int,int> dp[MxN+1];

int main(){
    int n,k,maxx=0;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        pair<int,int> p = {a[i].first,0};
        for (int j = 1; j < i; ++j) {
//            cout << dp[j].first - k << ' ' << a[i].first <<' '<< dp[j].first << ' ';
            if (dp[j].second >= p.second &&\
                dp[j].first - k <= a[i].first &&\
                dp[j].first >= a[i].first) {
                p = dp[j];
//                cout << p.first << ',' << p.second << '\n';
            }
        }
        dp[i].first = a[i].first;
        dp[i].second = p.second + a[i].second;
        maxx = max(maxx,dp[i].second);
        cout << '\n';
    }
    cout << maxx ;
    return 0;
}