#include<bits/stdc++.h>
#include "testlib.h"
const int MAX = 100000 + 10;

int p[MAX];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int MIN_N = 3;
    int MAX_N = 100000;

    int MIN_W = 1;
    int MAX_W = 100;

    int n = inf.readInt(MIN_N, MAX_N);
    inf.readChar('\n');

    for(int i = 0 ; i < n ; i++) p[i] = i;
    for(int i = 0 ; i < n-1 ; i++) {
        int x, y, w;
        x = inf.readInt(0, n-1);
        inf.readSpace();
        y = inf.readInt(0, n-1);
        inf.readSpace();
        w = inf.readInt(MIN_W, MAX_W);
        inf.readChar('\n');
        ensuref(find(x) != find(y), "No cycle allowed");
        p[find(x)] = find(y);
    }

    for(int i = 1 ; i < n ; i++) {
        ensuref(find(i) == find(0), "Input must be a connected tree");
    }
    inf.readEof();

    return 0;
}

