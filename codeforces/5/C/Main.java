import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
    String s = in.next();
    int n = s.length() + 1;
    int[] balance = new int[n];
    balance[0] = 0;
    int min = 0;
    int max = 0;
    for (int i = 1; i <= n; i++) {
      balance[i] =  balance[i - 1] + (s.charAt(i - 1) == '(' ? 1 : -1);
      min = Math.min(min, balance[i]);
      max = Math.max(max, balance[i]);
    }
    int[] same_left = new int[n];
    int[] first = new int[max - min + 1];
    Arrays.fill(first, -1);
    for (int i = 0; i < n; i++) {
      same_left[i] = first[balance - min];
      first[balance[i] - min] = i;
    }
    int[] ans = new int[n];
    ans[0] = 0;
    for (int i = 1; i < n; i++) {
      if (balance[i - 1] > balance[i]) {
        int j = same_left[i];
        if (j >= 0) {
          ans[i] = ans[j] + i - j;
        }
      }
    }
    max = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i] > max) {
        max = ans[i];
        cnt = 1;
      } else
      if (ans[i] == max) {
        cnt++;
      }
    }
    if (max == 0) cnt = 1;
    out.println(max + " " + cnt);
	}
	
	FastScanner in;
	PrintWriter out;
	
	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
 
	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
 
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in), 32768);
			st = null;
		}
		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}
 
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
 
	public static void main(String[] args) {
		new Main().run();
	}
}
