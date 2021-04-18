#include <iostream>
#include <vector>

using namespace std;
#define MxN 100000

int dp[MxN+1];
typedef struct sc{
    int x,y,w;
}sc;
sc schedule[MxN+1];
vector<int> set_sc[MxN+1];
int value(int i){
//    cout << i << "\n";
    if (i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int j = i-1;
    while(j>0 && schedule[i].x < schedule[j].y)
        j--;
    if(value(i-1) > schedule[i].w + value(j)) {
        set_sc[i] = set_sc[i-1];
        return dp[i] = value(i-1);
    }
    else{
        set_sc[i] = set_sc[j];
        set_sc[i].push_back(i);
        return dp[i] = schedule[i].w + value(j);
    }
}

int main(){
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> schedule[i].x >> schedule[i].y >> schedule[i].w;
        dp[i] = -1;
    }
    cout << value(n) << '\n';
    cout << set_sc[n].size()<< "\n";
    for(int it:set_sc[n])
        cout << it << ' ';
    return 0;
}

//#include <iostream>
//#include <list>
//using namespace std;
//
//#define MxN 100000
//
//pair<int,pair<int,int>> schedule[MxN+1];
//int dp[MxN+1];
//list<int> dp_select[MxN+1];
//
//int weight(int start,int stop,int stick) {
////    cout << start <<'\n';
//    if (start > stop) {
//        return 0;
//    }
//    if (dp[start] != -1)
//        return dp[start];
//    int x = weight(start+1,stop,stick);
//    int y = 0;
//    if (start == 4)
//        cout << stick << '\n';
//    if(stick < schedule[start].first)
//        y = schedule[start].second.second + weight(start+1,stop,schedule[start].second.first);
//    dp_select[start] = dp_select[start+1];
//    if(y>x) {
//        dp_select[start].push_back(start);
//    }
//    return dp[start] = max(x,y);
//}
//
//int main(){
//    int n;
//    cin >> n;
//    for (int i=1;i<=n;i++){
//        int x,y,w;
//        cin >> x >> y >> w;
//        schedule[i] = {x,{y,w}};
//    }
//    for (int i=0;i<=n+1;i++)
//        dp[i] = -1;
//    cout << weight(1,n,0) << '\n';
//    cout << dp_select[1].size() << '\n';
//    for(auto it=dp_select[1].rbegin();it!=dp_select[1].rend();it++){
//        cout << *it << ' ';
//    }
//    return 0;
//}
