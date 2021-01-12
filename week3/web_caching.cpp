#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int main(){
    unordered_set<int> s;
    int n,m,miss=0;
    cin >> n >> m;
    queue<int> q;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        if(s.find(x) == s.end()){
            miss++;
            s.insert(x);
            q.push(x);
            if(q.size()>n){
                s.erase(q.front());
                q.pop();
            }
        }
    }
    cout << miss ;
    return 0;
}