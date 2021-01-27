#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    set<int> all_size;
    cin >> n >> q;
    int a[n+1];
    a[0] = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[i] = x+a[i-1];
    }
    for(int i=0;i<n;i++){
        for(int j =i+1;j<=n;j++)
            all_size.insert(a[j]-a[i]);
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        cout << (all_size.find(x)!=all_size.end()? 'Y':'N');
    }
    return 0;
}