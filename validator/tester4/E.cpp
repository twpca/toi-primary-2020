#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int MNN = 1;
    int MXN = 10000;
    int MNK = 1;
    int MXK = 100;
    int MXS = 2000;
    int MNW = 1;
    int MXW = 200;

    int n = inf.readInt(MNN, MXN);
    inf.readSpace();
    int k = inf.readInt(MNK, MXK);
    inf.readChar('\n');

    int sum = 0;
    char cmd[100];
    REP(i,1,k) {
        sprintf(cmd, "[rgb]{1,%d}", MXS);
        string s = inf.readToken(cmd, "str");
        inf.readSpace();
        inf.readInt(MNW, MXW);
        inf.readChar('\n');

        sum += s.length();
    }

    sprintf(cmd, "[rgbx]{%d,%d}", MNN, MXN);
    inf.readToken(cmd, "");
    inf.readChar('\n');

    ensuref(sum <= MXS, "sum of string should <= MXS");
    inf.readEof();

    return 0;
}

