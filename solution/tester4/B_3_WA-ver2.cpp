// O(n) DP
// 3rd biggest not cosidered
#include<bits/stdc++.h>
#define F first
#define S second
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using P = pair<int,int>;
using T = tuple<int,int,int>;
int n;
P dp[M];
vector<P> e[M];
P dfs(int cur,int fa) {
    P res;
    dp[cur] = make_pair(0, 0);
    
    auto upd = [](P mx, int val, bool dup=false) {
        if (val > mx.F) {
            mx.S = mx.F;
            mx.F = val;
        } else if (val > mx.S && (val != mx.F || dup)) {
            mx.S = val;
        }
        return mx;
    };
    auto upd2 = [upd](P mx, P val, int a) {
        mx = upd(mx, val.F + a);
        mx = upd(mx, val.S + a);
        return mx;
    };

    P mx1, mx2;
    for (auto i:e[cur]) if (i.F!=fa) {
        res = upd2(res, dfs(i.F, cur), 0);
        res = upd2(res, dp[i.F], i.S);

        dp[cur] = upd2(dp[cur], dp[i.F], i.S);
        mx1 = upd(mx1, dp[i.F].F + i.S, true);
        mx2 = upd(mx2, dp[i.F].S + i.S, true);
    }

    if (mx1.S) {
        res = upd(res, mx1.F + mx1.S);
    }
    for (auto i:e[cur]) if (i.F!=fa) {
        int w2 = mx2.F;
        if (w2 == i.S + dp[i.F].S) {
            w2 = mx2.S;
        }
        if (w2) {
            res = upd(res, w2 + dp[i.F].F + i.S);
        }

        int w1 = mx1.F;
        if (w1 == i.S + dp[i.F].F) {
            w1 = mx1.S;
        }
        if (w1) {
            res = upd(res, w1 + dp[i.F].F + i.S);
        }
    } 
    return res;
}
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) e[i].clear();
        REP(i,1,n-1) {
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            x++;
            y++;
            e[x].push_back(make_pair(y,z));
            e[y].push_back(make_pair(x,z));
        }

        printf("%d\n", dfs(1, -1).S);
    }
    return 0;
}
