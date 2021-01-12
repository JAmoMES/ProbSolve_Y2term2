#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int a[n];
    a[0] = 0;
    map<int,int> price;
    price[1000000001] = n;
    int y=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        y += x;
        a[i] = y;
    }
    for(int i=1;i<=n;i++){
        int minn = 1000000000;
        for(int j=0;j+i<=n;j++){
            minn = min(minn,a[j+i]-a[j]);
        }
        price[minn] = i-1;
    }
    for(int i=0;i<k;i++){
        int m;
        cin >> m;
        if(price.upper_bound(m) == price.end())
            cout << "1";
        cout << price.upper_bound(m)->second << "\n";
    }
    return 0;
}
