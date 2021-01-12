#include <iostream>
using namespace std;

int main(){
    int n,i,ans = 1;
    cin >> n;
    int count = 1;
    for(i =2; count<n ; i++){
        count = i*i;
        ans += 2;
    }
    if(i%2==0 && n%2!=0) ans--;
    else if(i%2!=0 && n%2==0) ans--;
    else ans-=2;
    cout << ans;
    return 0;
}

