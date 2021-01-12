#include <iostream>
using namespace std;

int main(){
    int n,m,j=0;
    cin >> n >> m;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    int maxx = a[0];
    for(int i=0;i<m;i++){
        for(;j<b[i]-1;j++){
            maxx = max(maxx,a[j]);
        }
        //cout << maxx << " " << a[b[i]-1] << " ";
        if(b[i] == 1 || maxx < a[b[i]-1]) cout << "0" << endl;
        else cout << maxx-a[b[i]-1]+1 << ' ' << endl;
    }
    return 0;
}

