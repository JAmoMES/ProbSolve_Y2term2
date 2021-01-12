#include <iostream>
#include <stack>
using namespace std;

void rail(int n){
    while(1){
        stack<int> s;
        bool possible = 1;
        int coach = 1;
        for(int i=0;i<n;i++) {
            int num;
            cin >> num;
            if (num == 0) return;
            if(!possible) continue;
            for (int i = coach; i <= num; i++) {
                s.push(i);
                coach++;
            }
            if (!s.empty() && s.top() == num) s.pop();
            else possible = 0;
        }
        cout << (s.empty()? "Yes\n":"No\n");
    }
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        rail(n);
        cout << "\n";
    }
    return 0;
}
