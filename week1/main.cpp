#include <iostream>
using namespace std;

int main() {
    int n,count=0;
    cin >> n;
    int a[n+2];
    a[0] = 0;
    a[n+1] = 0;
    for (int i=0;i<n;i++){
        cin  >> a[i+1];
    }
    for(int i=1;i<n+1;i++){
        if(a[i-1]<a[i] && a[i+1]<a[i])
            count++;
    }
    cout << count;
    return 0;
}
