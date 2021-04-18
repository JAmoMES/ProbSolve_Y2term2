#include <iostream>

using namespace std;

#define MxN 1000

int a[MxN+1];

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int food = 0,hungry =0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        food += a[i];
        if (food >= k)
            food -= k;
        else{
            if (food < m){
                hungry = -1;
                break;
            }
            food = 0;
            hungry += 1;
        }
    }
    cout << hungry;
    return 0;
}