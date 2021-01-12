#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    map<int,int> price;
    price[1000000001] = n;
    int y=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        y += x;
        price[y] = i;
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
