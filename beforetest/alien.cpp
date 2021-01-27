#include <iostream>
using namespace std;

int bye_bye(int Si,int Sj,int posi,int posj,int r){
    return (Si-posi)*(Si-posi) + (Sj-posj)*(Sj-posj) <= r*r;
}

int main(){
    int n,Si,Sj,r,count = 0;
    cin >> n >> Si >> Sj >> r;
    for(int i=0;i<n;i++){
        int posi,posj;
        cin >> posi >> posj;
        if(bye_bye(Si,Sj,posi,posj,r))
            count++;
    }
    cout << count;
    return 0;
}

