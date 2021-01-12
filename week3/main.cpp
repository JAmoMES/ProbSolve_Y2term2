//#include <iostream>
//#include <list>
//using namespace std;
//
//int main() {
//    int a,b;
//    cout << a << b;
//    list<int> l1,l2;
//    for(int i=0;i<a;i++){
//        l1.push_back(i+1);
//    }
//    for(int i=0;i<b;i++){
//        l2.push_back(i+a+1);
//    }
//    for(auto it:l1){
//        cout << it << " ";
//    }
//    cout << endl;
//    for(auto it:l2){
//        cout << it << " ";
//    }
//    cout << endl;
//    list<int>::reverse_iterator it = l2.rbegin();
//
//    return 0;
//}
#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<double> s;
    double x = 0.0000001;
    for(int i=0;i<n;i++){
        double f;
        cin >> f;
        if(s.find(f) == s.end()){
            s.insert(f);
        }
        else {
            s.insert(f+x);
            x += 0.000001;
        }
        cout << s.size() << '\n';
    }
    for(auto it:s)
        cout << it << " ";
    return 0;
}