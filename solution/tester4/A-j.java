// O(n)
import java.util.*;

public class A {
    public static void main(String[] args) { new A().run(); }

    void run() {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String ans = "";
        
        int cnt = 0;
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if (c>='0' && c<='9') {
                cnt = cnt * 10 + (c-48);
            } else {
                if (cnt==0) cnt = 1;
                for (int j=0; j<cnt; j++) {
                    ans += c;
                }
                cnt = 0;
            }
        }

        System.out.printf("%s\n", ans);
    }
}

