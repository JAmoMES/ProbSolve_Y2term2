#include <iostream>
#include <unordered_set>
using namespace std;

int enemy[100001];
unordered_set<int> blank;

void union_set(unordered_set<int> **a,unordered_set<int> **b,unordered_set<int> *set_enemy,unordered_set<int> *s[]){
    if ((*a)->size() < (*b)->size()) swap(a,b);
//    cout << "set[a]={";
//    for (auto it:**a)
//        cout << it << ", ";
//    cout << "}\n";
//    cout << "set[b]={";
//    for (auto it:**b)
//        cout << it << ", ";
//    cout << "}\n";
    for(auto it:**b){
        if(set_enemy->find(it) != set_enemy->end()){
//            cout << "error"<< '\n';
            *a = &blank;
            *b = &blank;
            return ;
        }
        (*a)->insert(it);
        s[it] = *a;
    }
    //unordered_set<int> *tmp = *b;
    *b = *a;
    //free(tmp);
}

int main(){
    int n,m;
    cin >> n >> m;
    unordered_set<int> *s[n+1];
    for(int i=1;i<=n;i++){
        s[i] = (unordered_set<int> *)malloc(sizeof(unordered_set<int>));
        s[i]->insert(i);
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(ans) continue;
        if(enemy[a]){
            if(s[a]->find(b) != s[a]->end()){
                ans = i;
                continue;
            }
            if(s[b]->find(enemy[a]) == s[b]->end()){
                union_set(&s[b],&s[enemy[a]],s[a],s);
            }
        }
        if(enemy[b]){
            if(s[b]->find(a) != s[b]->end()){
                ans = i;
                continue;
            }
            if(s[a]->find(enemy[b]) == s[a]->end()){
                union_set(&s[a],&s[enemy[b]],s[b],s);
            }
        }
        if (s[a]->empty() || s[b]->empty()) ans = i;
        enemy[a] = b;
        enemy[b] = a;
//        for(int i=1;i<=n;i++){
//            cout << "set[" << i << "]={";
//            for (auto it:*s[i])
//                cout << it << ", ";
//            cout << "}\n";
//        }
    }
    cout << (ans? ans:m);
    return 0;
}