//#include <iostream>
//#include <list>
//using namespace std;
//
//int main(){
//    list<int> l1,l2;
//    for(int i=0;i<6;i++)
//        l1.push_back(i);
//    for(int i=6;i<12;i++)
//        l2.push_back(i);
//    auto it = l1.begin();
//    advance(it,3);
//    l1.erase(l1.begin(), it);
//    auto it1 = l2.begin();
//    advance(it1,3);
//    l2.reverse();
//    l1.splice(l1.begin(),l2,it1,l2.begin());
//    for(auto it2:l1)
//        cout << it2 << " ";
//    return 0;
//}

//#include <iostream>
//#include <list>
//
//std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
//{
//    for (auto &i : list) {
//        ostr << " " << i;
//    }
//    return ostr;
//}
//
//int main ()
//{
//    std::list<int> list1 = { 1, 2, 3, 4, 5 };
//    std::list<int> list2 = { 10, 20, 30, 40, 50 };
//
//    auto it = list1.begin();
//    std::advance(it, 2);
//
//    list1.splice(it, list2);
//
//    std::cout << "list1: " << list1 << "\n";
//    std::cout << "list2: " << list2 << "\n";
//    std::cout << *it << " " << *list1.end() <<"\n";
//    list2.splice(list2.begin(), list1, it, list1.end());
//
//    std::cout << "list1: " << list1 << "\n";
//    std::cout << "list2: " << list2 << "\n";
//}

//#include <iostream>
//#include <list>
//using namespace std;
//
//int main(){
//    list<int> l;
//    for (int i=1; i<=4; ++i)
//        l.push_back(i);      // mylist1: 1 2 3 4
//
//    list<int> *l1,*l2;
//    l1 = &l;
//    l2 = &l;
//    for(auto it:*l1)
//        cout << it << " ";
//    cout << endl;
//    for(auto it:*l2)
//        cout << it << " ";
//    cout << endl;
//    auto it = l2->begin();
//    advance(it,2);
//    l1->splice(l1->begin(),*l2,it);
//    if(l1==l2) cout << "Yes";
//    for(auto it:*l1)
//        cout << it << " ";
//    cout << endl;
//    for(auto it:*l2)
//        cout << it << " ";
//    cout << endl;
//    return 0;
//}

#include <iostream>
#include <list>
#include <set>
using namespace std;

int main(){
    int l;
    cin >> l ;
    int y = 0;
    list<int> l1[l+1];
    for(int i=0;i<l;i++){
        int x;
        cin >> x;
        for(int j=y+1;j<=y+x;j++){
            l1[i].push_back(j);
        }
        y+=x;
    }
    auto it = l1[0].begin();
    advance(it,3);
    l1[0].splice(it,l1[1]);
    for(auto it1 : l1[0])
        cout << it1 << " ";
    cout << endl;
    for(auto it1 : l1[1])
        cout << it1 << " ";
    cout << endl;
    return 0;
}