#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    int pos =0;
    for(int i=0;i<m;i++){
        int walk;
        cin >> walk;
        pos +=walk;
        if(pos > n){
            pos = n;
            continue;
        }
        pos+=a[pos];
        if(pos < 0) pos = 0;
    }
    cout << pos;
    return 0;
}