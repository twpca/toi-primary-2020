// O(nS + k)
import java.util.*;

class Aho {
    class Node {
        int w, sw, fail;
        int[] nxt, dp;
        Node () {
            nxt = new int[3];
            w = 0;
            sw = 0;
            fail = 0;
        }
    }

    int id;
    Node[] nodes;
    Aho() { id = 0; }
    Aho(int totlen) {
        nodes = new Node[totlen+1];
        for (int i=0; i<=totlen; i++) {
            nodes[i] = new Node();
        }
        id = 0;
    }
    int cid(char c) {
        if (c=='r') return 0;
        if (c=='g') return 1;
        if (c=='b') return 2;
        return -1;
    }
    void add(String s,int w) {
        int cur = 0;
        for (int i=0; i<s.length(); i++) {
            int c = cid(s.charAt(i));
            if (nodes[cur].nxt[c] == 0) {
                nodes[cur].nxt[c] = ++id;
            }
            cur = nodes[cur].nxt[c];
        }
        nodes[cur].w += w;
    }
    void make_fail() {
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add(0);
        while (q.size() != 0) {
            int cur = q.peek();
            q.remove();
            nodes[cur].sw = nodes[cur].w + nodes[nodes[cur].fail].sw;

            for(int nc=0; nc<=2; nc++) if (nodes[cur].nxt[nc] != 0) {
                int nxt = nodes[cur].nxt[nc];
                int f = nodes[cur].fail;

                while (f!=0 && nodes[f].nxt[nc]==0) f = nodes[f].fail;
                if (cur!=0 && nodes[f].nxt[nc]!=0) {
                    nodes[nxt].fail = nodes[f].nxt[nc];
                } else {
                    nodes[nxt].fail = 0;
                }
                q.add(nxt);
            }
        }
    }
    int do_dp(int _n, String s) {
        for(int i=0;i<=id;i++) {
            nodes[i].dp = new int[_n+1];
            for (int j=0; j<_n+1; j++) nodes[i].dp[j] = -1;
        }

        nodes[0].dp[0] = 0;
        for(int i=0;i<=_n-1;i++) for(int cur=0;cur<=id;cur++) if (nodes[cur].dp[i] != -1) {
            int c = cid(s.charAt(i+1));
            int nxt = 0;
            for(int cc=0;cc<=2;cc++) if (cc==c || c==-1) {
                nxt = cur;
                while (nxt!=0 && nodes[nxt].nxt[cc]==0) nxt = nodes[nxt].fail;
                if (nodes[nxt].nxt[cc]!=0) nxt = nodes[nxt].nxt[cc];
                nodes[nxt].dp[i+1] = Math.max(nodes[nxt].dp[i+1], nodes[nxt].sw + nodes[cur].dp[i]);
            }
        }

        int res = 0;
        for(int i=0;i<=id;i++) res = Math.max(res, nodes[i].dp[_n]);
        return res;
    } 
}

public class E {
    int M;
    int n,m;
    Aho aho;
    String in;

    public E() {
        M = 100005;
        aho = new Aho(M);
    }
    public static void main(String[] args) { new E().run(); }

    void run() {
        Scanner sc = new Scanner(System.in);
        int w;
        String tmp;

        n = sc.nextInt();
        m = sc.nextInt();
        for (int i=1; i<=m; i++) {
            tmp = sc.next();
            w = sc.nextInt();
            aho.add(tmp, w);
        }
        in = sc.next();
        in = new String(" ").concat(in);
        aho.make_fail();

        System.out.printf("%d\n", aho.do_dp(n, in));
    }
}


