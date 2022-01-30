// O(log MOD)
#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;

class Mint {
public:
    LL x;
    LL MOD;
    LL _mod(LL a) { return (a%MOD + MOD) % MOD; }
    LL _pw(LL a,LL b) {
        LL res = 1, tmp = _mod(a);
        while (b) {
            if (b&1) res = res * tmp % MOD;
            tmp = tmp * tmp % MOD;
            b >>= 1;
        }
        return res;
    }
    Mint () { x = 0; }
    Mint (LL a, LL _MOD) { MOD = _MOD; x = _mod(a); }
    bool operator == (const Mint &a) { return x == a.x; }
    bool operator != (const Mint &a) { return x != a.x; }
    Mint operator + (const Mint &a) { return Mint(x + a.x, MOD); }
    Mint operator - (const Mint &a) { return Mint(x - a.x, MOD); }
    Mint operator * (const Mint &a) { return Mint(x * a.x, MOD); }
    Mint operator / (const Mint &a) { return Mint(x * _pw(a.x, MOD-2), MOD); }
};
int main()
{
    int tt,mod;
    Mint a,b;
    Mint x,y;
    Mint nx,ny;

    auto read = [&](Mint &t) {
        LL tmp;
        scanf("%lld", &tmp);
        t = Mint(tmp, mod);
    };

    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &mod);
        read(a); read(b);
        read(x); read(y);
        read(nx); read(ny);

        assert(x != nx);

        Mint x3, y3;
        Mint m = (y-ny)/(x-nx);
        Mint k = ny - m*nx;
        x3 = m * m - x - nx;
        y3 = m * x3 + k;
        if (y3*y3 != x3*x3*x3 + a*x3 + b) {
            printf("mod=%lld a=%lld b=%lld x1=%lld y1=%lld x2=%lld y2=%lld\n",(long long)mod,a.x,b.x,x.x,y.x,nx.x,ny.x);
            printf("m=%lld k=%lld\n",m.x,k.x);
            
            printf("(x1,y1) on curve? %d\n", y*y == x*x*x + a*x + b);
            printf("(x2,y2) on curve? %d\n", ny*ny == nx*nx*nx + a*nx + b);

            printf("%d\n", y == m*x + k);
            printf("%d\n", ny == m*nx + k);
            printf("%d\n", y3 == m*x3 + k);

            printf("x3=%lld y3=%lld\n",x3.x,y3.x);
            assert(0); //???
        }
        printf("%lld %lld\n", x3.x, y3.x);
    }

    return 0;
}
