#include <iostream>
#include <map>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int,int> status;
    list<int> l[100000];
    int top_like = 0;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(x == 1) status[y]++;
        else status[y]--;
        l[status[y]].push_front(y);
        if(status[y]>top_like)
            top_like = status[y];
        while (top_like>=0){
            bool stop = false;
            for(auto it = l[top_like].begin();it!= l[top_like].end();it++){
                if (status[*it] == top_like ){
                    cout << *it << "\n";
                    stop = true;
                    l[top_like].begin() = it;
                    break;
                }
            }
            if(stop) break;
            l[top_like].clear();
            top_like--;
        }
    }
    return 0;
}