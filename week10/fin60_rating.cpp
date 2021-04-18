#include <iostream>

using namespace std;

#define MxN 100000

int Max_rating[MxN+1];

pair<int,int> rate[MxN+1];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int x;
        cin >> x;
        if (i - rate[x].second <=6){
            rate[x].first +=1;
            rate[x].second = i;
        } else{
            Max_rating[x] = max(Max_rating[x],rate[x].first);
            rate[x].first = 1;
            rate[x].second = i;
        }
        for (int j=1;j<=n;j++){
//            cout << Max_rating[j] << "&" << rate[j].first <<',' << rate[j].second << ' ';
        }
//        cout << '\n';
    }
    int maxx = 0,post;
    for (int i=1;i<=n;i++){
        Max_rating[i] = max(Max_rating[i],rate[i].first);
        if (maxx < Max_rating[i]){
            maxx = Max_rating[i];
            post = i;
        }

    }
    cout << post << ' '<< maxx;
    return 0;
}