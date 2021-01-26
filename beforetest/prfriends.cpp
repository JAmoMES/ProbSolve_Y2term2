#include <iostream>
#include <cmath>
using namespace std;

bool not_prime[200001];

int main(){
    int l,r;
    cin >> l >> r;
    not_prime[1] = 1;
    for(int i=2;i<=ceil(sqrt(r));i++) {
        if(not_prime[i]) continue;
        int multi = i+i;
        while(multi <= r){
            not_prime[multi] = true;
            multi += i;
        }
    }
    int pr_friend=0;
    for(int i = l ;i<=r-2 ;i++){
        if(!not_prime[i]&&!not_prime[i+2])
            pr_friend++;
    }
    cout << pr_friend;
    return 0;
}
