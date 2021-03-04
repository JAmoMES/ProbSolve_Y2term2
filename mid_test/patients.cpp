#include <iostream>
using namespace std;

int well[1021];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int patient = 0;
    for(int i=1;i<=n;i++){
        int p;
        cin >> p;
        patient -= well[i];
        for(int j=0;j<p;j++){
            int a,b;
            cin >> a >> b;
            patient += a;
            well[i+b] += a;
            //cout << patient << "\n";
        }
        cout << patient << "\n";
    }
    return 0;
}