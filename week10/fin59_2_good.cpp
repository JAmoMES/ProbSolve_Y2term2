#include <iostream>

using namespace std;

#define MxN 20

int x[MxN+1][MxN+1];
double y[MxN+1][MxN+1];
int n,m;

double diff(int mean,int row,int column){
    double d1=0,d2=0;
    for (int i=0;i<n;i++){
        d1 += abs(mean - x[i][column]);
    }
    for (int i=0;i<m;i++){
        d2 += abs(mean - x[row][i]);
    }
    return (d1+d2)/((double)n+(double )m-1);
}

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> x[i][j];
        }
    }

    double min = 10000000000;
    int row,column;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            y[i][j] = diff(x[i][j],i,j);
//            cout << y[i][j] << ' ';
            if (min > y[i][j]) {
                min = y[i][j];
                row = i;
                column = j;
            }
        }
    }
    cout << x[row][column];
    return 0;
}