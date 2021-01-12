#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    int num;
    node *prev;
    node *next;
public:
    explicit node(int num,node *prev = NULL,node *next = NULL){
        this->num = num;
        this->prev = prev;
        this->next = next;
    }
    node *forward(){
        if(this->next!=NULL)
            return this->next;
        return this;
    }
    node *back(){
        if(this->prev!=NULL)
            return this->prev;
        return this;
    }
    void display(){
        cout << this->num << "\n";
    }
};

class list{
public:
    node *begin;
    node *end;
public:
    list(node *begin,node *end){
        this->begin = begin;
        this->end = end;
    }
    list(int num1,int num2){
        this->begin = new node(num1);
        node *go = this->begin;
        node *to = go;
        for(int i = num1+1;i<=num2 ;i++){
            to = new node(i,go);
            go->next = to;
            go = to;
        }
        this->end = to;
    }
    int front() {
        if(this->begin == NULL) return 0;
        return this->begin->num;
    }
    int back() {
        if(this->end == NULL) return 0;
        return this->end->num;
    }
    void reverse() {
        node *rthis = this->begin;
        while(rthis!=NULL){
            swap(rthis->next,rthis->prev);
            rthis = rthis->prev;
        }
        swap(this->begin,this->end);
    }
    list *cut(node *cut_pos){
        if(cut_pos->next == NULL) return NULL;
        node *new_begin = cut_pos->next;
        list *new_list = new list(new_begin,this->end);
        cut_pos->next = NULL;
        new_begin->prev = NULL;
        this->end = cut_pos;

        return new_list;
    }
    void connect(list *next_list){
        this->end->next = next_list->begin;
        next_list->begin->prev = this->end;
        this->end = next_list->end;
    }
    void display(){
        node *start = this->begin;
        while(start!=NULL){
            cout << start->num << " ";
            start = start->next;
        }
        cout << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l,n;
    cin >> l >> n;
    int y = 0;
    list *l1[l];
    unordered_map<int,list *> All_dna;
    for(int i=0;i<l;i++){
        int x;
        cin >> x;
        l1[i] = new list(y+1,y+x);
        All_dna[l1[i]->front()] = l1[i];
        All_dna[l1[i]->back()] = l1[i];
        y+=x;
    }
    list *dna = l1[0];
    char command;
    auto it = dna->begin;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command == 'F'){
            it = it->forward();
        }
        else if(command == 'B'){
            it = it->back();
        }
        else if(command == 'C'){
            list *cut_list = dna->cut(it);
            if(cut_list!=NULL) {
                All_dna[cut_list->front()] = cut_list;
                All_dna[cut_list->back()] = cut_list;
            }
            int x;
            cin >> x;
            list *next_dna = All_dna[x];
            if(next_dna->front() != x)
                next_dna->reverse();
            dna->connect(next_dna);
            it = it->forward();
            All_dna.erase(next_dna->front());
            All_dna.erase(next_dna->back());
            free(next_dna);
//            for(auto it2:All_dna){
//                cout << it2.first << ": ";
//                if(it2.second!=NULL)
//                    it2.second->display();
//            }
        }
        cout << it->num << "\n";
    }
    return 0;
}
/*
4 10
3
4
2
5
B
F
C 9
C 4
F
B
F
C 3
F
C 14
*/
