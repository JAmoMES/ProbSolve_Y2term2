#include <iostream>
#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;
    list<string> word;
    word.push_back("start");
    auto it = word.begin();
    for(int i=0;i<n;i++){
        char command;
        cin >> command;
        if(command == 'l'){
            if(it != word.begin())
                it--;
        }
        else if(command == 'r'){
            if(++it == word.end())
                it--;
        }
        else if(command == 'i'){
            string new_word;
            cin >> new_word;
            it = word.emplace(++it,new_word);
        }
        else if(command == 'b'){
            if(it == word.begin())
                continue;
            word.erase(it--);
        }
        else if(command == 'd'){
            if(++it == word.end()){
                it--;
                continue;
            }
            word.erase(it--);
        }
//        cout << *it << endl;
//        for(auto it2:word)
//            cout << it2 <<  " ";
//        cout << endl;
    }
    auto it2 = word.begin();
    it2++;
    for(;it2 != word.end();it2++)
        cout << *it2 <<  " ";
    cout << endl;
    return 0;
}
/*
9
i Hello
i world
l
i this
r
b
d
l
d*/
