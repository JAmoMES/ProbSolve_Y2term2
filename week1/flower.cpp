#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int l,n,i;
    cin >> l >> n;
    float count=0;
    for(i=0;count<n;i++){
        int x = l*i;
        count = ceil((x*x+x)/2);
    }
    cout << i-1;
    return 0;
}

