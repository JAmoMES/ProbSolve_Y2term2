#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int p;
    while (cin >> p, p) x--;
    cout << (x % 2 ? 'C' : 'K');
    return 0;
}
