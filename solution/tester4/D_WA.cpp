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

        // sort and double
        sort(in+1, in+n+1, [](P a, P b){            
            LL w1 = a.y * b.x;
            LL w2 = b.y * a.x;
            return w1 > w2;
        });
        REP(i,n+1,2*n) in[i] = in[i-n];
        
        // calc
        set<int> s1;
        multiset<LL> s2;
        LL ans = 0;

        s1.insert(0);
        s2.insert(0LL);
        REP(i,1,2*n) {
            fr[i] = fr[i-1] + in[i].w;

            while (i - *s1.begin() > n) {
                s2.erase(s2.find(fr[*s1.begin()]));
                s1.erase(s1.begin());
            }
            ans = max(ans, fr[i] - *s2.begin());
            s1.insert(i);
            s2.insert(fr[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
