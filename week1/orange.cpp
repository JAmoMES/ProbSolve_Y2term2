#include <iostream>
#include <stack>
using namespace std;

int main(){
    int l,n,count=0;
    cin >> l >> n;
    stack<int> s;
    for(int i=l;i>0;i--){
        s.push(i*i);
    }
    while(n>0){
        if(n - s.top()>=0){
            n = n - s.top();
            s.pop();
        }
        else break;
    }
    while (!s.empty()){
        count++;
        s.pop();
    }
    cout << count;
    return 0;
}