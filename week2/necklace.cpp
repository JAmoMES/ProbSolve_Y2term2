#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class node{
    public:int num;
    node *next;

    public:node(int num){
        this->num = num;
        this->next = NULL;
    }
    void display(){
        node *play = this;
        while(play != NULL){
            cout << play->num << "\n";
            play = play->next;
        }
        cout << "\n";
    }
    void insert(node *play){
        node *last = this->next;
        this->next = play;
        while(play->next != NULL){
            play = play->next;
        }
        play->next = last;
    }
};

int main(){
    int n;
    cin >> n;
    vector<node *> it;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        node *new_node = new node(i+1);
        it.push_back(new_node);
        s.insert(i+1);
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        it[y-1]->insert(it[x-1]);
        s.erase(x);
    }
    it[*s.begin()-1]->display();
    return 0;
}