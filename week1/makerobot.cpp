/*
#include <iostream>
using namespace std;

void store(int *store_first,int *store_next,int x){
    if(*store_first > x){
        *store_first -= x;
    }
    else {
        x -= *store_first;
        *store_first = 0;
        *store_next -= x;
    }
}

int main(){
    int h1,h2,b1,b2,money =0;
    cin >> h1 >> h2 >> b1 >> b2;
    int x,y;
    cin >> x >> y;
    int two_color,a=h1-b1,b=h2-b2;
    int white = min(h1,b1),black = min(h2,b2);
    h1-= white; b1-= white;
    h2 -= black; b2 -= black;
    if(black + white >= x+y){
        cout << x+y;
        return 0;
    }
    if(a<=0 && b>=0) {
        two_color=min(abs(a),b);
        b1 -= two_color;
        h2 -= two_color;
    }
    else if(a>=0 && b<=0) {
        two_color=min(a,abs(b));
        b2 -= two_color;
        h1 -= two_color;
    }
    else two_color = 0;

    if(white+black >= x){
        money += x;
        if(b1 == 0 && h1 == 0)
            store(&black,&white,x);
        else if(b2 == 0 && h2 == 0)
            store(&white,&black,x);
        x = 0;
    }
    else {
        money += white+black;
        white = 0;
        black = 0;
        x -= white+black;
    }
    h1 += white;b1 += white;
    h2 += black;b2 += black;
    two_color += min(b1,h2)+min(b2,h1);
    if(two_color >= y){
        money += y;
        y = 0;
    }
    else {
        money += two_color;
        y = y-two_color;
    }
    cout << money;
    return 0;
}

*/

#include <iostream>
using namespace std;

void destroy(int *color,int *head,int *body){
    (*color)--;
    (*head)++;
    (*body)++;
}

void make_robot(int *robot_type, int *head, int *body){
    int new_robot = min((*head), (*body));
    (*robot_type) += new_robot;
    (*head)-=new_robot;
    (*body)-=new_robot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h1, h2, b1, b2, money = 0;
    cin >> h1 >> h2 >> b1 >> b2;
    int x, y;
    cin >> x >> y;
    int two_color = 0, white = 0,black = 0;
    make_robot(&white, &h1, &b1);
    make_robot(&black, &h2, &b2);
    make_robot(&two_color, &h1, &b2);
    make_robot(&two_color, &h2, &b1);
    //cout << white << black << two_color;
    while(white+black > x){
        if((h1 > 0 || b1 > 0) && black > 0) destroy(&black,&h2,&b2);
        else if ((h2 > 0 || b2 > 0) && white > 0) destroy(&white,&h1,&b1);
        else if ((white && black)&&two_color+2<=y){
            destroy(&black,&h2,&b2);
            destroy(&white,&h1,&b1);
        }
        else break;
        make_robot(&two_color, &h1, &b2);
        make_robot(&two_color, &h2, &b1);
    }
    if(white+black < x) money+=white+black;
    else money += x;
    if(two_color < y) money+=two_color;
    else money += y;
    cout << money;
    return 0;
}