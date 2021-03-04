#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cover_it(int m, vector<pair<int,int>> &seg, vector<pair<int,int>> &res) {
    pair<int,int> cover = {0, m};
    sort(seg.begin(), seg.end());
    for (int i = 0; i < seg.size(); i) {
        if (seg[i].first > cover.first) return 0;
        pair<int,int> *max = &seg[i];
        for (i++; i < seg.size(); i++) {
            if (seg[i].first > cover.first) break;
            if (seg[i].second > max->second) max = &seg[i];
        }

        res.push_back(*max);
        cover.first = max -> second;
        if (cover.first >= cover.second) return res.size();
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int l, r;
        vector<pair<int,int>> seg;
        while(cin >> l >> r , l||r){
            seg.emplace_back(l,r);
        }
        vector<pair<int,int>> res;
        if(!cover_it(m, seg, res)){
            cout << 0 << "\n";
            continue;
        }
        cout << res.size() << "\n";
        for (auto it:res) {
            cout << it.first << " " << it.second << "\n";
        }
        printf("\n");
    }
    return 0;
}
/*
2

1
-1 0
-5 -3
2 5
0 0

1
-1 0
0 1
0 0*/
