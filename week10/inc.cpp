#include <iostream>
#include <vector>

using namespace std;

#define MxN 1000
#define INF 1<<30

pair<int,int> dp[MxN+1];
vector<int> seq[MxN+1];
int val[MxN+1];

int main(){
    int n,maxx=0;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> val[i];
    }
    dp[0] = {0,1<<31};
    for (int i = 1; i <= n; ++i) {
        pair<int,int> p = {0,val[i]};
        int k = 0;
        for (int j = 0; j < i; j++) {
            if (dp[j].second < val[i] && dp[j].first >= p.first ){
                p = dp[j];
                k = j;
            }
        }
        seq[i] = seq[k];
        seq[i].push_back(val[i]);
        dp[i] = {seq[i].size(),val[i]};
        maxx = max(maxx,(int)seq[i].size());
    }
    cout << maxx << '\n';
    for (int i=1;i<=n;i++){
        if (seq[i].size() == maxx){
            for(int it:seq[i]){
                cout << it << ' ';
            }
            break;
        }
    }
    return 0;
}