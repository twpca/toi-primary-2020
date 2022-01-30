// O(n log n)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
using namespace std;
using LL = long long;
struct P {
    LL x,y,w;
    P () {}
    P (LL a,LL b, LL c) { x=a; y=b; w=c; }
};
int n;
P in[2*M];
LL fr[2*M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) {
            LL x,y,w;
            scanf("%lld %lld %lld",&x,&y,&w);
            if (y<0) { x*=-1, y*=-1; }
            in[i] = P(x,y,w);
        }

        sort(in+1, in+n+1, [](P a, P b){            
            LL w1 = a.y * b.x;
            LL w2 = b.y * a.x;
            return w1 > w2;
        });

        // dedup
        int pos = 1;
        REP(i,2,n) {
            LL w1 = in[pos].y * in[i].x;
            LL w2 = in[i].y *in[pos].x;
            if (w1 == w2) {
                in[pos].w += in[i].w;
            } else {
                in[++pos] = in[i];
            }
        }
        n = pos;

        // double
        REP(i,n+1,2*n) in[i] = in[i-n];

        // calc
        multiset<LL> s2;
        LL ans = 0;
        pos = 0;
        s2.insert(0LL);

        REP(i,1,2*n) {
            fr[i] = fr[i-1] + in[i].w;

            while (i - pos > n) {
                s2.erase( s2.find(fr[pos]) );
                pos++;
            }
            ans = max(ans, fr[i] - *s2.begin());
            s2.insert(fr[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
