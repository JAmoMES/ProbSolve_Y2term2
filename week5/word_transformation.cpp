#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
using namespace std;

int bfs(unordered_map<string,vector<string>> &graph,string &start,string &then){
    queue<string> q;
    q.push(start);
    unordered_map<string,int> level;
    level[start] = 0;
    while(!q.empty()){
        string x = q.front();
        q.pop();
        for(auto it:graph[x]) {
            if(level.find(it) == level.end()){
                level[it] = level[x]+1;
                if(it == then) return level[it];
                q.push(it);
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    int n;
    unordered_set<string> dic[10];
    cin >> n;
    while(n--){
        cout << "\n";
        while(cin >> word && word!="*"){
            dic[word.size()].insert(word);
        }
        unordered_map<string,vector<string>> graph;
        for(int i=1;i<=10;i++){
            for(auto it:dic[i]){
                for(auto it2:dic[i]){
                    int dif = 0;
                    for(int j=0;j<i;j++){
                        if(it[j]!=it2[j]) dif++;
                    }
                    if(dif == 1){
                        graph[it].push_back(it2);
                    }
                }
            }
        }

        string str;
        cin.ignore();
        while (getline(cin,str),!str.empty()){
            stringstream ss(str);
            string word1,word2;
            ss >> word1 >> word2;
            int level = bfs(graph,word1,word2);
            cout << word1 << " " << word2 << " " << level << "\n";
        }
    }
    return 0;
}

/*
1

dip
lip
mad
maple
may
pad
pid
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

 */
