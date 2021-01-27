#include <iostream>
using namespace std;

int times[101];
int point[101];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        times[a]++;
        point[a] = max(b,point[a]);
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(times[i]<=5)
            sum+=point[i];
    }
    cout << sum;
    return 0;
}


