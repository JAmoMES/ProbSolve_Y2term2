#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l,n;
    cin >> l >> n;
    int y = 0;
    list<int> l1[l+1];
    unordered_map<int,list<int> *> All_dna;
    for(int i=0;i<l;i++){
        int x;
        cin >> x;
        for(int j=y+1;j<=y+x;j++){
            l1[i].push_back(j);
        }
        All_dna[l1[i].front()] = &l1[i];
        All_dna[l1[i].back()] = &l1[i];
        y+=x;
    }
    list<int> *dna = l1;
    char command;
    auto it = dna->begin();
    for(int i=0;i<n;i++){
        cin >> command;
        if(command == 'F'){
            if(++it == dna->end()) {
                it--;
                cout << *it << "\n";
                continue;
            }
        }
        else if(command == 'B'){
            if(it == dna->begin()) {
                cout << *it << "\n";
                continue;
            }
            it--;
        }
        else if(command == 'C'){
            int x;
            cin >> x;
            list<int> *next_dna = All_dna[x];
            if(next_dna->back() == x)
                next_dna->reverse();
            auto it2 = next_dna->begin();
            next_dna->splice(next_dna->begin(),*dna,dna->begin(),++it);
            if(dna->size()>0) {
                All_dna[dna->front()] = dna;
                All_dna[dna->back()] = dna;
            }
            dna = next_dna;
            it = it2;
        }
        cout << *it << "\n";
    }
    return 0;
}
/*
4 10
3
4
2
5
B
F
C 9
C 4
F
B
F
C 3
F
C 14
*/
//#include <iostream>
//#include <list>
//using namespace std;
//
//list<int> *which_dna(int x,list<int> *l1) {
//    for (int i = 0;; i++) {
//        if (l1[i].front() == x || l1[i].back() == x)
//            return l1+i;
//    }
//}
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    int l,n;
//    cin >> l >> n;
//    int y = 0;
//    list<int> l1[l+1];
//    for(int i=1;i<=l;i++){
//        int x;
//        cin >> x;
//        for(int j=y+1;j<=y+x;j++){
//            l1[i-1].push_back(j);
//        }
//        y+=x;
//    }
//    list<int> *dna = l1;
//    char command;
//    auto it = dna->begin();
//    for(int i=0;i<n;i++){
//        cin >> command;
//        if(command == 'F'){
//            if(++it == dna->end()) {
//                it--;
//                cout << *it << "\n";
//                continue;
//            }
//        }
//        else if(command == 'B'){
//            if(it == dna->begin()) {
//                cout << *it << "\n";
//                continue;
//            }
//            it--;
//        }
//        else if(command == 'C'){
//            int x;
//            cin >> x;
//            list<int> *next_dna = which_dna(x,l1);
//          if(dna == next_dna){
//                l1[l].splice(l1[l].begin(),*dna,dna->begin(),++it);
//                dna = l1+l;
//                it = dna->end();
//                it--;
//            }
//            if(next_dna->back() == x)
//                next_dna->reverse();
//            auto it2 = next_dna->begin();
//            next_dna->splice(next_dna->begin(),*dna,dna->begin(),++it);
//            dna = next_dna;
//            it = it2;
//
//        }
//        cout << *it << "\n";
//        for(auto it2 : *dna)
//             cout << it2 << " ";
//        cout << endl;
//    }
//    return 0;
//}