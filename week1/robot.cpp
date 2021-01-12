#include <iostream>
using namespace std;

int main(){
    int x=0,y=0;
    string walk;
    cin >> walk;
    for (int i = 0;i < walk.length();i++){
        if(walk[i] == 'N') y++;
        else if(walk[i] == 'S') y--;
        else if(walk[i] == 'E') x++;
        else if(walk[i] == 'W') x--;
        else {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y;
    return 0;
}


