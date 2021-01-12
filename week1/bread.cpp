/*
#include <iostream>
using namespace std;

int main(){
    int w,h,m,n,maxx=0,maxx2=0,maxy=0,maxy2=0,x=0,y=0,x1,y1;
    cin >> w >> h >> m >> n;
    for (int i=0;i<m;i++){
        cin >> x1;
        if(maxx2 == 0) maxx2 = maxx;
        if(maxx < x1-x) {
            maxx2 = maxx;
            maxx = max(maxx,x1-x);
        }
        if(x1-x != maxx) {
            maxx2 = max(maxx2, x1 - x);
        }
        if(maxx2 == maxx) maxx2 = x1-x;
        x = x1;
    }
    x1 = w;
    if(maxx2 == 0) maxx2 = maxx;
    if(maxx < x1-x) {
        maxx2 = maxx;
        maxx = max(maxx,x1-x);
    }
    if(x1-x != maxx)
        maxx2 = max(maxx2,x1-x);
    if(maxx2 == maxx) maxx2 = x1-x;
    x = x1;
    for (int i=0;i<n;i++){
        cin >> y1;
        if(maxy2 == 0) maxy2 = maxy;
        if(maxy < y1-y) {
            maxy2 = maxy;
            maxy = max(maxy,y1-y);
        }
        if(y1-y != maxy)
            maxy2 = max(maxy2,y1-y);
        if(maxy2 == maxy) maxy2 = y1-y;
        y = y1;
    }
    y1 = h;
    if(maxy2 == 0) maxy2 = maxy;
    if(maxy < y1-y) {
        maxy2 = maxy;
        maxy = max(maxy,y1-y);
    }
    if(y1-y != maxy)
        maxy2 = max(maxy2,y1-y);
    if(maxy2 == maxy) maxy2 = y1-y;
    if(maxx2 == 0) maxx2 = maxx;
    if(maxy2 == 0) maxy2 = maxy;
    //cout << maxx << " " << maxx2 << " "<< maxy << " " << maxy2 << endl;
    cout << maxx*maxy << " ";
    if(maxx2*maxy!=maxx*maxy && maxx*maxy2!=maxx*maxy)
        cout << max(maxx2*maxy,maxx*maxy2);
    else cout << maxx2*maxy2;
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main(){
    int w,h,m,n,x=0,x1,y=0,y1;
    cin >> w >> h >> m >> n;
    int a[m+2],b[n+2];
    a[0] = 0;
    b[0] = 0;
    for(int i=1;i<=m;i++) {
        cin >> x1;
        a[i] = x1 - x;
        x = x1;
    }
    a[m+1] = w - x;
    for(int i=1;i<=n;i++) {
        cin >> y1;
        b[i] = y1 - y;
        y = y1;
    }
    b[n+1] = h - y;
    sort(a,a+m+2,greater<int>());
    sort(b,b+n+2,greater<int>());
    cout << a[0]*b[0] << " ";
    x1 = 0; y1 =0;
    for(int i =1 ;i<=m+1;i++){
        if(a[i] != a[0])
            x1 = a[i];
    }
    for(int i =0 ;i<=m+1;i++){
        if(b[i] != b[0])
            y1 = b[i];
    }
    if (x1 == 0) x1=a[0];
    if (y1 == 0) y1=b[0];
    cout << max(a[0]*y1,x1*b[0]);
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main(){
    int w,h,m,n,x=0,x1,y=0,y1;
    cin >> w >> h >> m >> n;
    int a[m+2],b[n+2];
    a[0] = 0;
    b[0] = 0;
    for(int i =1 ;i<=m;i++){
        cin >> x1;
        a[i] = x1-x;
        x = x1;
    }
    a[m+1] = w - x;
    for(int i =1 ;i<=n;i++){
        cin >> y1;
        a[i] = y1-y;
        y = y1;
    }
    b[m+1] = h - y;
    sort(a,a+m+1,greater<int>());
    sort(b,b+n+1,greater<int>());
    cout << a[0]*b[0] << " ";
    if (a[1] == 0) a[1]=a[0];
    if (b[1] == 0) b[1]=b[0];
    cout << max(a[0]*b[1],a[1]*b[0]);
    return 0;
}*/

#include <iostream>
using namespace std;

int main(){
    int w,h,m,n,x=0,x1,y=0,y1;
    pair<int,int> maxx;
    cin >> w >> h >> m >> n;
    int a[m+1],b[n+1];
    for(int i =0 ;i<m;i++){
        cin >> x1;
        a[i] = x1-x;
        x = x1;
    }
    a[m] = w - x;
    for(int i =0 ;i<n;i++){
        cin >> y1;
        b[i] = y1-y;
        y = y1;
    }
    b[n] = h - y;
//    for(int i =0 ;i<=m;i++){
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//    for(int i =0 ;i<=n;i++){
//        cout << b[i] << ' ';
//    }
//    cout << endl;
    maxx.first = 0;
    maxx.second = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(maxx.first < a[i]*b[j]){
                if(maxx.first != maxx.second)
                    maxx.second = maxx.first;
                maxx.first = a[i]*b[j];
            }
            else if(maxx.first > a[i]*b[j])
                maxx.second = max(maxx.second,a[i]*b[j]);
        }
    }
    if(maxx.second == 0) maxx.second = maxx.first;
    cout << maxx.first << ' ' << maxx.second;
}