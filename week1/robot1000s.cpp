#include <iostream>
using namespace std;

int main(){
    int x=0,y=0,k;
    int n,s,e,w,error;
    string walk;
    cin >> walk;
    cin >> k;
    for (int i = 0;i < walk.length();i++){
        if(walk[i] == 'N') {
            y++; n++;
        }
        else if(walk[i] == 'S') {
            y--; s++;
        }
        else if(walk[i] == 'E') {
            x++; e++;
        }
        else if(walk[i] == 'W') {
            x--;w++;
        }
    }
    if(x>=0 && y>=0)
        error = s+w;
    else if(x>=0 && y<=0)
        error = n+w;
    else if(x<=0 && y>=0)
        error = s+e;
    else
        error = n+e;
    x = abs(x);y=abs(y);
    if(error >= k) cout << (x+y+k)*2;
    else if(error <= k) cout << (x+y+2*error-k)*2;
    return 0;
}


