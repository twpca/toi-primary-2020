#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 2005
using namespace std;
class Aho {
public:
    class Node {
    public:
        int nxt[3], w, sw, fail;
        vector<int> dp;
        Node () {
            MSET(nxt, 0);
            w = 0;
            sw = 0;
            fail = 0;
        }
    };
    int id;
    vector<Node> nodes;

    int cid (char c) {
        if (c=='r') return 0;
        if (c=='g') return 1;
        if (c=='b') return 2;
        return -1;
    }
    Aho () { id = 0; }
    Aho (int totlen) {
        nodes = vector<Node> (totlen+1);
        id = 0;
    }
    void add(const char s[], int w) {
        int cur = 0;
        while (*s) {
            int c = cid(*s);
            if (!nodes[cur].nxt[c]) nodes[cur].nxt[c] = ++id;
            cur = nodes[cur].nxt[c];
            s++;
        }
        nodes[cur].w += w;
    }
    void make_fail() {
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            nodes[cur].sw = nodes[cur].w + nodes[nodes[cur].fail].sw;

            REP(nc,0,2) if (nodes[cur].nxt[nc]) {
                int nxt = nodes[cur].nxt[nc];
                int f = nodes[cur].fail;

                while (f && !nodes[f].nxt[nc]) f = nodes[f].fail;
                if (cur && nodes[f].nxt[nc]) {
                    nodes[nxt].fail = nodes[f].nxt[nc];
                } else {
                    nodes[nxt].fail = 0;
                }
                q.push(nxt);
            }
        }
    }
    int do_dp(int _n, char s[]) {
        REP(i,0,id) nodes[i].dp = vector<int> (_n+1, -1);

        nodes[0].dp[0] = 0;
        REP(i,0,_n-1) REP(cur,0,id) if (nodes[cur].dp[i] != -1) {
            int c = cid(s[i+1]);
            int nxt = 0;
            REP(cc,0,2) if (cc==c || c==-1) {
                nxt = cur;
                while (nxt && !nodes[nxt].nxt[cc]) nxt = nodes[nxt].fail;
                if (nodes[nxt].nxt[cc]) nxt = nodes[nxt].nxt[cc];
                nodes[nxt].dp[i+1] = max(nodes[nxt].dp[i+1], nodes[nxt].sw + nodes[cur].dp[i]);
            }
        }

        int res = 0;
        REP(i,0,id) res = max(res, nodes[i].dp[_n]);
        return res;
    }
};
int n,m;
Aho aho;
char in[10005];
void init() {
    int w;
    char tmp[2005];

    aho = Aho(M);
    REP(i,1,m) {
        scanf("%s%d", tmp, &w);
        aho.add(tmp, w);
    }
    scanf("%s", in+1);

    aho.make_fail();
}
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        init();
        printf("%d\n", aho.do_dp(n, in));
    }
    return 0;
}
