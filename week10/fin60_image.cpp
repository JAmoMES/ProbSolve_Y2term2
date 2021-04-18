#include <iostream>
using namespace std;

#define MxN 100

int a[MxN+11][MxN+11];

int avg(int x,int y,int h){
    int sum = 0,count=0;
    for (int i = -h; i <= 0; i++) {
//        cout << i << '\n';
        for (int j =-i-h ; j <= i+h; j++) {
            if (a[x+i][y+j]<0) continue;
            sum += a[x+i][y+j];
            count+=1;
//            cout << i << ',' << j << ' ';
        }
//        cout << '\n';
    }
    for (int i = 1; i <= h; ++i) {
//        cout << i << '\n';
        for (int j = -(h)+i; j <=(h)-i ; ++j) {
            if (a[x+i][y+j]<0) continue;
            sum += a[x+i][y+j];
            count+=1;
//            cout << i << ',' << j << ' ';
        }
//        cout << '\n';
    }
//    cout << '(' << sum << ',' << count << ") ";
    return sum / count;
}

int main(){
    int n,m,h;
    cin >> m >> n >> h;
    for (int i=0;i<n+2*h;i++){
        for (int j = 0; j<h; j++) {
            a[i][j] = -1;
            a[i][j+m+h] = -1;
        }
    }
    for (int i=0;i<m+2*h;i++){
        for (int j = 0; j<h; j++) {
            a[j][i] = -1;
            a[j+n+h][i] = -1;
        }
    }
    for (int i = h; i < n+h; ++i) {
        for (int j = h; j < m+h; ++j) {
            cin >> a[i][j];
        }
    }
//    for (int i = 0; i < n+2*h; ++i) {
//        for (int j = 0; j < m+2*h; ++j) {
//            cout << a[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    for (int i = h; i < n+h; ++i) {
        for (int j = h; j < m+h; ++j) {
            cout << avg(i,j,h) << ' ';
        }
        cout << '\n';
    }
    return 0;
}