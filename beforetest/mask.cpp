#include <iostream>
using namespace std;

pair<int,int> find_max(int round,int n){
    pair<int,int> maxx;
    maxx.second = 0;
    for(int i=n*round;i<n*round+n;i++){
        int x;
        cin >> x;
        if(maxx.second < x){
            maxx.second = x;
            maxx.first = i+1;
        }
    }
    return maxx;
}

int main(){
    int n;
    cin >> n;
    pair<int,int> max1 = find_max(0,n);
    pair<int,int> max2 = find_max(1,n);
    pair<int,int> max3 = find_max(2,n);
    pair<int,int> max4 = find_max(3,n);
    if(max1.second < max2.second) swap(max1,max2);
    if(max3.second < max4.second) swap(max3,max4);
    if(max1.second < max3.second) swap(max1,max3);
    cout << max1.first << " " << max3.first << " " << max2.first << " " << max4.first;
    return 0;
}