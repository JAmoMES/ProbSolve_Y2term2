#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,pos=1,count=0,plus;
    cin >> n;
    string equation[n*2-1];
    for(int i = 0;i<n*2-1;i++){
        cin >> equation[i];
    }
    for(int i = 0;i<n*2-1;i++){
        if(i%2 == 0) {
            if(pos == 1)
                count += stoi(equation[i]);
            else count -= stoi(equation[i]);
        }
        else{
            if(equation[i] == "+") pos = 1;
            else pos = 0;
        }
    }
    cout << count;
    return 0;
}
