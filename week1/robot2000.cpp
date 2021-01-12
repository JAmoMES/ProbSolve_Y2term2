#include <iostream>
using namespace std;

int printR(int di,int di2){
    while (di%4 != di2){
        cout << 'R';
        di++;
    }
    return di%4;
}

int main(){
    int di = 0,di2;
    string walk;
    cin >> walk;
    for (int i = 0;i < walk.length();i++){
        if(walk[i] == 'N') di2 = 0;
        else if(walk[i] == 'E') di2 = 1;
        else if(walk[i] == 'S') di2 = 2;
        else if(walk[i] == 'W') di2 = 3;
        else {
           di = 0;
           cout << 'Z';
           continue;
        }
        di = printR(di,di2);
        cout << 'F';
    }
    return 0;
}

