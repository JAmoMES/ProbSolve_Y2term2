#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    x -=2558;
    int p;
    while(cin >> p,p) x--;
    cout << (x%2? 'C':'K');
    return 0;
}