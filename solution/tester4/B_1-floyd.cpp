// O(n^3)
#include<bits/stdc++.h>
#define F first
#define S second
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
#define INF 1000000000
using namespace std;
using P = pair<int,int>;
int n,dis[M][M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n)REP(j,1,n) dis[i][j] = INF;
        REP(i,1,n) dis[i][i] = 0;
        REP(i,1,n-1) {
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            x++;
            y++;
            dis[x][y] = dis[y][x] = z;
        }

        REP(k,1,n)REP(i,1,n)REP(j,1,n)
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

        int mx=-1, mx2=-1;
        REP(i,1,n) REP(j,1,n) mx = max(mx, dis[i][j]);
        REP(i,1,n) REP(j,1,n) if (dis[i][j] != mx) mx2 = max(mx2, dis[i][j]);

        printf("%d\n", mx2);
    }
    return 0;
}

