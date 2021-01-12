#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[1000] = {0};
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        for(int j = 2*x+1;j < 2*y;j++){
            a[j]++;
        }
    }
    sort(a,a+n+1,greater<int>());
    cout << *a;
    return 0;
}