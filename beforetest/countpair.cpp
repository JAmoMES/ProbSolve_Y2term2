#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l_bound,u_bound;
    map<int,int> pos_min;
    map<int,int> pos_max;
    cin >> n >> l_bound >> u_bound;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(pos_min[a[i]]) pos_min[a[i]] = min(pos_min[a[i]],i);
        else pos_min[a[i]] = i;
        pos_max[a[i]] = max(pos_min[a[i]],i);
    }
    pos_min[2000000001] = n;
    pos_max[2000000001] = n;
    long long sum = 0;
    for(int i=0;i<n;i++){
        if(pos_max[a[i]] == pos_min[a[i]]){
            pos_max.erase(a[i]);
            pos_min.erase(a[i]);
        }
        else pos_min[a[i]]++;
        auto l = pos_min.lower_bound(l_bound - a[i]);
        auto u = pos_max.upper_bound(u_bound - a[i]);
        if(a[i]+l->first > u_bound) break;
        sum += (--u)->second - l->second +1;
//        for(auto it: pos_min)
//            cout << it.first << "," << it.second << " ";
//        cout << "\n";
//        for(auto it: pos_max)
//            cout << it.first << "," << it.second << " ";
//        cout << "\n";
//        cout << sum << "\n";
    }
    cout << sum << '\n';
    return 0;
}
            /* only 50% can debug to 100%*/
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    int n,lower_bound,upper_bound;
//    cin >> n >> lower_bound >> upper_bound;
//    int a[n];
//    for(int i=0;i<n;i++)
//        cin >> a[i];
//    sort(a,a+n);
//    long long sum = 0;
//    int l = n-1,u = n-1;
//    for(int i=0;i<n;i++){
//        if(l<=i) l = i+1;
//        while (l > i+1){
//            if(a[i]+a[l] > lower_bound) l--;
//            else break;
//        }
//        while (l > i && l < n){
//            if(a[i]+a[l] < lower_bound) l++;
//            else break;
//        }
//        while (u > i){
//            if(a[i]+a[u] > upper_bound) u--;
//            else break;
//        }
//        if(l<=u) sum += u-l+1;
//        else break;
//    }
//    cout << sum << '\n';
//    return 0;
//}