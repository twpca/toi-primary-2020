// O(log MOD)
import java.util.*;

public class C {
    int tt, mod;
    Mint a,b;
    Mint x,y;
    Mint nx,ny;

    public static void main(String[] args) { new C().run(); }

    Mint read(Scanner sc) {
        long tmp = sc.nextLong();
        return new Mint(tmp, mod);
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        tt = sc.nextInt();
        while (tt != 0) {
            tt--;
            mod = sc.nextInt();
            a = read(sc);
            b = read(sc);
            x = read(sc);
            y = read(sc);
            nx = read(sc);
            ny = read(sc);

            Mint x3, y3;
            Mint m = y.min(ny).div(x.min(nx));
            Mint k = ny.min(m.mut(nx));
            x3 = m.mut(m).min(x).min(nx);
            y3 = m.mut(x3).add(k);
            System.out.printf("%d %d\n", x3.x, y3.x);
        }
    }

    class Mint {
        long x, MOD;
        public Mint() {}
        public Mint(long a,long _MOD) { MOD = _MOD; x = _mod(a); }
        long _mod(long a) { return (a%MOD + MOD) % MOD; }
        long _pw(long a,long b) {
            long res=1, tmp=_mod(a);
            while (b != 0) {
                if (b%2 != 0) res = res * tmp % MOD;
                tmp = tmp * tmp % MOD;
                b /= 2L;
            }
            return res;
        }
        Mint add(Mint a) { return new Mint(x + a.x, MOD); }
        Mint min(Mint a) { return new Mint(x - a.x, MOD); }
        Mint mut(Mint a) { return new Mint(x * a.x, MOD); }
        Mint div(Mint a) { return new Mint(x * _pw(a.x, MOD-2), MOD); }
    }
}


