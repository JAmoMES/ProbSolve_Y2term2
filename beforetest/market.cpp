//#include <iostream>
//#include <list>
//using namespace std;
//
//int main(){
//    int n,sum = 0;
//    cin >> n;
//    list<pair<int,int>> buy;
//    list<pair<int,int>> sell;
//    for(int i=0;i<n;i++){
//        int command;
//        cin >> command;
//        switch (command) {
//            case 1:
//                int p,a;
//                cin >> p >> a;
//                for(auto it = sell.begin();it != sell.end() ; it++){
//                    cout << it->first << " " << p << "\n";
//                    if(it->first <= p){
//                        if(it->second > a){
//                            sum += p * a;
//                            it->second -=a;
//                        }
//                        else{
//                            sum += p * it->second;
//                            a -= it->first;
//                            sell.erase(it--);
//                        }
//                        if(a = 0) break;
//                    }
//                }
//                if(a){
//                    buy.emplace_back(p,a);
//                }
//                break;
//            case 2:
//                int q,b;
//                cin >> q >> b;
//                for(auto it = buy.begin();it != buy.end() ; it++){
//                    cout << it->first << " " << q << "\n";
//                    if(it->first >= q){
//                        if(it->second > b){
//                            sum += q * b;
//                            it->second -=b;
//                            b = 0;
//                            break;
//                        }
//                        else{
//                            sum += q * it->second;
//                            b -= it->first;
//                            sell.erase(it--);
//                        }
//                    }
//                }
//                if(b){
//                    sell.emplace_back(q,b);
//                }
//                break;
//        }
//        cout << "sell\n";
//        for(auto it:sell){
//            cout << "{" << it.first << "," << it.second << "} ";
//        }
//        cout << "\n";
//        cout << "buy\n";
//        for(auto it:buy){
//            cout << "{" << it.first << "," << it.second << "} ";
//        }
//        cout << "\n";
//    }
//
//    cout << sum ;
//    return 0;
//}
//#include <iostream>
//#include <list>
//#include <queue>
//using namespace std;
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    int n,sum = 0;
//    cin >> n;
//    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > buy;
//    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > sell;
//    for(int i=0;i<n;i++){
//        int command;
//        cin >> command;
//        switch (command) {
//            case 1:
//                int p,a;
//                cin >> p >> a;
//                while(!sell.empty()){
//                    auto it  = sell.top();
//                    if(it.first <= p){
//                        if(it.second > a){
//                            sum += p * a;
//                            it.second -=a;
//                            sell.pop();
//                            sell.push(it);
//                            a = 0;
//                        }
//                        else{
//                            sum += p * it.second;
//                            a -= it.first;
//                            sell.pop();
//                        }
//                        if(a == 0) break;
//                    }
//                    else break;
//
//                }
//                if(a){
//                    buy.push({p,a});
//                }
//                break;
//            case 2:
//                int q,b;
//                cin >> q >> b;
//                while(!buy.empty()){
//                    auto it  = buy.top();
//                    if(it.first >= q){
//                        if(it.second > b){
//                            sum += q * b;
//                            it.second -=b;
//                            buy.pop();
//                            buy.push(it);
//                            b = 0;
//                        }
//                        else{
//                            sum += q * it.second;
//                            b -= it.first;
//                            buy.pop();
//                        }
//                        if(b == 0) break;
//                    }
//                    else break;
//
//                }
//                if(b){
//                    sell.push({q,b});
//                }
//                break;
//        }
//    }
//
//    cout << sum ;
//    return 0;
//}

#include <iostream>
#include <list>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum = 0;
    cin >> n;
    map<int,int> sell;
    map<int,int> buy;
    sell[1000000] = 1;
    buy[-1000000] = 1;
    for(int i=0;i<n;i++){
        int command;
        cin >> command;
        switch (command) {
            case 1:
                int p,a;
                cin >> p >> a;
                for(auto it = sell.begin();it != sell.end() ;it++){
                    cout << it->first << "," << it->second <<"\n";
                    if(it->first <= p){
                        if(it->second > a){
                            sum += p * a;
                            it->second -= a;
                            a = 0;
                        }
                        else{
                            sum += p * it->second;
                            a -= it->first;
                            sell.erase(it);
                        }
                        if(a == 0) break;
                    }
                    else break;
                }
                if(a){
                    buy[p] += a;
                }
                break;
            case 2:
                int q,b;
                cin >> q >> b;
                auto it = buy.upper_bound(q);
                if(it != buy.end()) {
                    while (true) {
                        cout << it->first << "," << it->second << "\n";
                        if (it->first >= q) {
                            if (it->second > b) {
                                sum += q * b;
                                it->second -= b;
                                b = 0;
                            } else {
                                sum += q * it->second;
                                b -= it->first;
                                buy.erase(it);
                            }
                            if (b == 0) break;
                        } else break;
                        if (it == buy.begin()) break;
                        it--;
                    }
                }
                if(b){
                   sell[q] += b;
                }
                break;
        }
        cout << "all = "<< sum << "\n";
    }
    cout << sum ;
    return 0;
}