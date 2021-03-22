#include <iostream>
#include <cmath>

using namespace std;

#define MxN 10

int farm[MxN+1][MxN+1];
int bird_in_row[MxN+1];

int main(){
    int r,c,b,t;
    cin >> r >> c >> b >> t;
    for (int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            cin >> farm[i][j];
            sum += farm[i][j];
        }
        bird_in_row[i]=sum;
    }
    int reduce = b/t;
    int times=0;
    for (int i =0;i<r;i++){
        times += (int)ceil((float )bird_in_row[i]/(float)reduce);
    }
    cout << times;
    return 0;
}