// O(n logn logn)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
#define F first
#define S second
using namespace std;
using P = pair<int,int>;
int n,dep[M],id[M];
int a1,a2;
set<int> s[M];
vector<P> e[M];
void upd(int x) {
    if (x > a1) {
        a2 = a1;
        a1 = x;
    } else if (x > a2 && x != a1) {
        a2 = x;
    }
}
void dfs(int cur,int fa) {
    auto merge = [&](int x,int y,int w) {
        int xid = id[x];
        int yid = id[y];
        if (s[xid].size() < s[yid].size()) swap(xid, yid);
        
        for (int i: s[yid]) {
            auto mx1 = s[xid].rbegin();
            auto mx2 = mx1; mx1++;
            upd(*mx1 + i - 2*w);
            if (mx2 != s[xid].rend()) upd(*mx2 + i - 2*w);
        }
        for (int i: s[yid]) {
            s[xid].insert(i);
        }
        s[yid].clear();
        id[x] = xid;
    };

    s[id[cur]].insert(dep[cur]);
    for (auto i: e[cur]) if (i.F != fa) {
        dep[i.F] = dep[cur] + i.S;
        dfs(i.F, cur);
        merge(cur, i.F, dep[cur]);
    }
}
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) s[i].clear();
        REP(i,1,n) e[i].clear();
        REP(i,1,n) id[i] = i;

        REP(i,1,n-1) {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            x++; y++;
            e[x].push_back(P(y,z));
            e[y].push_back(P(x,z));
        }

        a1 = a2 = 0;
        dep[1] = 0;
        dfs(1, -1);
        printf("%d\n", a2);
    }
    return 0;
}
