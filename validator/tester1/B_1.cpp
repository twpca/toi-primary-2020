#include<bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int MIN_N = 3;
    int MAX_N = 100;

    int MIN_W = 1;
    int MAX_W = 100;

    int n = inf.readInt(MIN_N, MAX_N);
    inf.readChar('\n');

    for(int i = 0 ; i < n-1 ; i++) {
        int x, y, w;
        x = inf.readInt(0, n-1);
        inf.readSpace();
        y = inf.readInt(0, n-1);
        inf.readSpace();
        w = inf.readInt(MIN_W, MAX_W);
        inf.readChar('\n');
    }
    inf.readEof();

    return 0;
}

