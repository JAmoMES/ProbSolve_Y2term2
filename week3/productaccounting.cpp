#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> product;
    for(int i=0;i<n;i++){
        int command,x;
        cin >> command >> x;
        if(product.find(x)==product.end())
            product[x] = 0;
        if(command == 1){
            int y;
            cin >> y;
            product[x]+=y;
        }
        else if(command == 2){
            cout << product[x] << "\n";
        }
        else if(command == 3){
            int y;
            cin >> y;
            cout << min(product[x],y) << "\n";
            product[x] -= min(product[x],y);
        }
    }
    return 0;
}