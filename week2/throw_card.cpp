#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        list<int> l;
        for(int i =0 ;i<n;i++){
            l.push_front(i+1);
        }
        cout << "Discarded cards:";
        while(l.size()!= 1){
            cout << " " << l.back();
            l.pop_back();
            if(l.size()!=1)
             cout << ",";
            else break;
            int x = l.back();
            l.pop_back();
            l.push_front(x);
        }
        cout << "\nRemaining card: " << *l.begin() << "\n";
    }
    return 0;
}
//#include <cstdio>
//#include <queue>
//using namespace std;
//
//int main() {
//    int n, x;
//    queue<int> q;
//
//    while (scanf("%d", &n), n) {
//        for (int i = 1; i <= n; i++) {
//            q.push(i);
//        }
//
//        printf("Discarded cards:");
//        while (q.size() > 1) {
//            printf(" %d", q.front());
//            q.pop();
//            x = q.front();
//            q.pop();
//            if (!q.empty())
//                printf(",");
//            q.push(x);
//        }
//        printf("\nRemaining card: %d\n", q.front());
//        q.pop();
//    }
//
//    return 0;
//}
/*10
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
9
Discarded cards: 1, 3, 5, 7, 9, 4, 8, 6
Remaining card: 2
3
Discarded cards: 1, 3
Remaining card: 2
100
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74, 78, 82, 86, 90, 94, 98, 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100, 16, 32, 48, 64, 80, 96, 24, 56, 88, 40, 8
Remaining card: 72
0
10
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
9
Discarded cards: 1, 3, 5, 7, 9, 4, 8, 6
Remaining card: 2
3
Discarded cards: 1, 3
Remaining card: 2
100
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74, 78, 82, 86, 90, 94, 98, 4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100, 16, 32, 48, 64, 80, 96, 24, 56, 88, 40, 8
Remaining card: 72
0
 */
