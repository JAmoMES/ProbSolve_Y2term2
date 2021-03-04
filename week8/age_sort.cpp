#include <iostream>

using namespace std;

int main(){
    int n;
    int age[100] = {0};
    while(scanf("%d",&n),n){
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            age[x]++;
        }
        string sep = "";
        for (int i =0;i<100;i++){
            while(age[i]){
                cout << sep << i;
                sep = " ";
                age[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}