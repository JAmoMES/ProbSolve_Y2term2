#include <iostream>
#include <map>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<pair<int,int>> s;
    s.push({0,0});
    map<int,int> ans;
    for (int i=0;i<n;++i){
        int x;
        cin >> x;
        if (s.top().first < x){
            s.push({x,i});
            continue;
        }
        while(!s.empty()){
            if(s.top().first <= x)
                break;
            pair<int,int> y = s.top();
            s.pop();
            int diff = min(y.first-x,y.first-s.top().first);
            ans[i - y.second] += diff;
            if(x > s.top().first)
                s.push({x,y.second});
        }
//        cout << ans.size() << '\n';
//        for(auto it:ans)
//            cout << it.first << " " << it.second << "\n";
    }
    int x = 0;
    while(!s.empty()){
        if(s.top().first <= 0)
            break;
        pair<int,int> y = s.top();
        s.pop();
        int diff = min(y.first,y.first-s.top().first);
        ans[n - y.second] += diff;
    }
    cout << ans.size() << '\n';
    for(auto it:ans)
        cout << it.first << " " << it.second << "\n";
    return 0;
}