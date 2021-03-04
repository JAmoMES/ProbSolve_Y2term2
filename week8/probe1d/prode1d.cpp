#include <iostream>
#include "probelib.h"
using namespace std;

void probe(int l, int r){
    if (l==r)
        probe_answer(l);
    int m = l + (r-l)/2;
    if(probe_check(l,m))
        probe(l,m);
    else
        probe(m+1,r);
}

int main(){
    int right = probe_init();
    probe(0,right-1);
    return 0;
}