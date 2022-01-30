#include<bits/stdc++.h>
#include "testlib.h"
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
class MillerRabin {
public:
    static LL pow(LL x,LL y,LL mod) {
        LL re = 1, tmp = x % mod;
        while (y) {
            if (y&1) re = re * tmp % mod;
            tmp = tmp * tmp % mod;
            y >>= 1;
        }
        return re;
    }
    static bool mr(LL x, LL t) {
        int c = 0;
        LL cur = x-1, tmp;
        while (!(cur&1)) {
            cur >>= 1;
            c++;
        }

        tmp = pow(t, cur, x);
        if (tmp==1 || tmp==x-1) return true;
        REP(i,1,c-1) {
            tmp = tmp * tmp % x;
            if (tmp==1) return false;
            if (tmp==x-1) return true;
        }
        return false;
    }
    static bool is_prime(LL x) {
        if (x<=1) return false;
        int ys[] = {2,7,61};
        for (int y: ys) if (y < x) {
            if (!mr(x,y)) return false;
        }
        return true;
    }
};
pair<int,int> solver(int _mod,int _a,int _b,int _x1,int _y1,int _x2,int _y2) {
    Mint a = Mint(_a, _mod);
    Mint b = Mint(_b, _mod);
    Mint x = Mint(_x1, _mod);
    Mint y = Mint(_y1, _mod);
    Mint nx = Mint(_x2, _mod);
    Mint ny = Mint(_y2, _mod);

    ensuref(y*y == x*x*x + a*x + b, "(x1,y1) should be on curve.");
    ensuref(ny*ny == nx*nx*nx + a*nx + b, "(x2,y2) should be on curve.");

    Mint m = (y-ny)/(x-nx);
    Mint k = ny - m*nx;
    Mint x3 = m * m - x - nx;
    Mint y3 = m * x3 + k;
    return make_pair((int)x3.x, (int)y3.x);
}
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int MXT = 100000;
    int MXM = 2147483647;

    int t = inf.readInt(1,MXT);
    inf.readChar('\n');

    REP(i,1,t) {
        int m = inf.readInt(2, MXM);
        inf.readSpace();
        int a = inf.readInt(0, m-1);
        inf.readSpace();
        int b = inf.readInt(0, m-1);
        inf.readSpace();

        int xx1 = inf.readInt(0, m-1);
        inf.readSpace();
        int yy1 = inf.readInt(0, m-1);
        inf.readSpace();

        int xx2 = inf.readInt(0, m-1);
        inf.readSpace();
        int yy2 = inf.readInt(0, m-1);
        inf.readChar('\n');

        ensuref(MillerRabin::is_prime(m), "m should be prime.");
        ensuref(xx1!=xx2, "x should not be identical.");

        int xx3, yy3;
        tie(xx3, yy3) = solver(m, a, b, xx1, yy1, xx2, yy2);
        ensuref(xx3!=xx2 && xx3!=xx1, "x3 should be different");

        ensuref((long long)t*m<=100000, "case 2: tm<=10^5");
    }
    inf.readEof();

    return 0;
}

