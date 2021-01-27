#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    int energy = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int x = a[i-1]-a[i];
        if (x>10)
            energy += x > 70 ? 70 : x;
    }
    cout << energy*10;
    return 0;
}