#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    map<pair<int,int>,int> vis;
    int fry = 0;
    int MX = 100; // 10^2
    int MXA = 100000; // 10^5
    int n = inf.readInt(1, MX);
    inf.readChar('\n');

    REP(i,1,n) {
        int x = inf.readInt(-MXA, MXA);
        inf.readSpace();
        int y = inf.readInt(-MXA, MXA);
        inf.readSpace();
        int w = inf.readInt(-MXA, MXA);
        inf.readChar('\n');

        auto p = make_pair(x,y);
        ensuref(vis[p] == false, "all coordinates should be different");
        vis[p] = true;

        ensuref(x!=0 || y!=0, "(x,y) != (0,0)");

        // all y are same
        if (i!=1) ensuref(y == fry, "y should all be identical");
        fry = y;
    }
    inf.readEof();

    return 0;
}
