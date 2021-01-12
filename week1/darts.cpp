#include <iostream>
#include <math.h>
using namespace std;

float distance(int x,int y){
    return sqrt(x*x + y*y);
}

int points(float a){
    if(a <= 2) return 5;
    if(a <= 4) return 4;
    if(a <= 6) return 3;
    if(a <= 8) return 2;
    if(a <= 10) return 1;
    return 0;
}

int main(){
    int n,point = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        float a = distance(x,y);
        point += points(a);
    }
    cout << point;
    return 0;
}

