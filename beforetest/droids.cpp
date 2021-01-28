#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,m;
    set<int> pos;
    pos.insert(-1000000001);
    pos.insert(1000000001);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pos.insert(x);
    }
    int last_robot = 1000000002,dis = 0;
    for(int i=0;i<m;i++){
        int y;
        cin >> y;
        pos.erase(last_robot);
        auto it = pos.lower_bound(y);
        auto it1 = pos.upper_bound(y);
        if(it == it1) it--;
        int work;
        if((y-*it <= *it1-y || *it1 == 1000000001) && *it != last_robot){
            work = *it;
        }
        else work = *it1;
        dis += abs(y-work);
        pos.insert(last_robot);
        last_robot = work;
    }
    cout << dis ;
    return 0;
}
