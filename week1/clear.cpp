#include <iostream>
using namespace std;

int main(){
    pair<int,int> a[3];
    int b[3];
    cin >> a[0].second >> a[1].second >> a[2].second;
    a[0].first = 0;
    a[1].first = 0;
    a[2].first = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int command;
        cin >> command;
        if(command == 1) a[0].first++;
        else if(command == 2) a[1].first++;
        else a[2].first++;
    }
    for(int i=0;i<3;i++)
        b[i] = a[i].first*a[i].second;
    sort(b,b+3);
    cout << b[0];
}

