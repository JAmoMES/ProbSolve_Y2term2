#include <iostream>
#include <set>
#include <cmath>
using namespace std;

double sunshine(int l,int h,int x,int y){
    return ceil((float)l + (float)(x*h)/(float)y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,h;
    cin >> n >> l >> h;
    set<double> mushroom;
    double plus = 0.0000001;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        for(int j=0;j<a;j++){
            double b;
            cin >> b;
            if(mushroom.find(b) == mushroom.end())
                mushroom.insert(b);
            else{
                mushroom.insert(b+plus);
                plus +=0.0000001;
            }
        }
        int x,y;
        cin >> x >> y;
        double new_l = sunshine(l,h,x,y);
        mushroom.erase(mushroom.lower_bound(new_l),mushroom.end());
//        for(auto it:mushroom)
//            cout << it << " ";
//        cout << "\n";
        cout << mushroom.size() << "\n";
    }
    return 0;
}
//#include <iostream>
//#include <map>
//#include <cmath>
//using namespace std;
//
//int sunshine(int l,int h,int x,int y){
//    return (int)ceil((float)l + (float)(x*h)/(float)y);
//}
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    int n,l,h;
//    cin >> n >> l >> h;
//    map<int,int> mushroom;
//    for(int i=0;i<n;i++){
//        int a;
//        cin >> a;
//        for(int j=0;j<a;j++){
//            int b;
//            cin >> b;
//            mushroom[b]++;
//        }
//        int x,y;
//        cin >> x >> y;
//        int new_l = sunshine(l,h,x,y);
//        mushroom.erase(mushroom.lower_bound(new_l),mushroom.end());
//        int sum = 0;
//        for(auto it:mushroom)
//            sum+= it.second;
//        cout << sum << "\n";
//    }
//    return 0;
//}