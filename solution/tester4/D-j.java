// O(n log n)
import java.util.*;

class P implements Comparable<P> {
    long x,y,w;
    public P() {}
    public P(long a,long b,long c) { x=a; y=b; w=c; }
    @Override
    public int compareTo(P a) {
        long w1 = y * a.x;
        long w2 = x * a.y;
        if (w1 > w2) return -1;
        if (w1 < w2) return 1;
        return 0;
    }
}

public class D {
    int M,n;
    P[] in;
    long[] fr;

    public D() {
        M = 300005;
        in = new P[M*2];
        fr = new long[M*2];
    }
    public static void main(String[] args) { new D().run(); }

    void run() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for (int i=1; i<=n; i++) {
            long x,y,w;
            x = sc.nextLong();
            y = sc.nextLong();
            w = sc.nextLong();
            if (y<0) { x*=-1; y*=-1; }
            in[i] = new P(x,y,w);
        }
        Arrays.sort(in, 1, n+1);

        // dedup
        int pos = 1;
        for (int i=2; i<=n; i++) {
            long w1 = in[pos].y * in[i].x;
            long w2 = in[i].y * in[pos].x;
            if (w1 == w2) {
                in[pos].w += in[i].w;
            } else {
                in[++pos] = in[i];
            }
        }
        n = pos;

        // double
        for (int i=n+1; i<=2*n; i++) in[i] = in[i-n];

        TreeMap<Long,Integer> mp = new TreeMap<Long,Integer> ();
        long ans = 0;
        pos = 0;
        mp.put(0L, 1);

        fr[0] = 0L;
        for (int i=1; i<=2*n; i++) {
            fr[i] = fr[i-1] + in[i].w;

            while (i - pos > n) {
                mp.put(fr[pos], mp.get(fr[pos]) - 1);
                if (mp.get(fr[pos]) == 0L) {
                    mp.remove(fr[pos]);
                }
                pos++;
            }
            ans = Math.max(ans, fr[i] - mp.firstKey());

            Integer cnt = mp.get(fr[i]);
            if (cnt == null) cnt = 0;
            mp.put(fr[i], cnt+1);
        }
        System.out.printf("%d\n", ans);
    }
}

