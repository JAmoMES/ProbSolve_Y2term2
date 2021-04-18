#include <iostream>

using namespace std;

#define MxN 1000

int a[2*MxN+1];
int b[2*MxN+1];

int main(){
    int n,h,maxx=0;
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i = 1; i <= 2*n; i++) {
        b[i] = b[i-1]+a[i];
    }
    for (int i =1; i <= 2*n ; i++){
        for (int j = 0; j <= i; j++) {
            if (b[i]-b[j] <= h)
                maxx = max(maxx,i-j);
        }
    }
    cout << min(n,maxx);
    return 0;
}