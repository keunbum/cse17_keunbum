import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int C = (int) 1e4;
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[] dp = new int[C + 1];
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			for (int j = C; j >= x; j--) {
				dp[j] = Math.max(dp[j], dp[j - x] + a[i]);
			}
		}
		int ans = C;
		for (int i = 0; i <= C; i++) {
			if (dp[i] >= m) {
				ans = i;
				break;
			}
		}
		out.println(ans);
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
