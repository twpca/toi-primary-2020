#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
bool vis[M];
vector<int> e[M];

bool is_tree(int n) {
    int cur;
    queue<int> q;
    MSET(vis, false);

    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i: e[cur]) if (!vis[i]) {
            vis[i] = true;
            q.push(i);
        }
    }

    int cnt = 0;
    REP(i,0,n-1) cnt += vis[i] ? 1 : 0;
    return cnt==n;
}

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int MNN = 3;
    int MXN = 100000;
    int MNW = 1;
    int MXW = 1;
    
    int n = inf.readInt(MNN, MXN);
    inf.readChar('\n');
    REP(i,1,n-1) {
        int x,y,z;
        x = inf.readInt(0, n-1);
        inf.readSpace();
        y = inf.readInt(0, n-1);
        inf.readSpace();
        z = inf.readInt(MNW, MXW);
        inf.readChar('\n');
        e[x].push_back(y);
        e[y].push_back(x);

        ensuref(x!=y, "no self loop");
    }
    inf.readEof();
    
    ensuref(is_tree(n), "input must be a tree");
    return 0;
}

