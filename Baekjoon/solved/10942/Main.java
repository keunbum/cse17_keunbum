import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int N = 2000;
	int[] a;
	boolean[][] dp;
	
	void solve() {
		int n = in.nextInt();
		a = new int [n];
		dp = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 1; i <= n; i++) {
			for (int s = 0, e = s + i - 1; e < n; s++, e++) {
				if (a[s] == a[e]) {
					dp[s][e] = (e - s <= 2) ? true : dp[s + 1][e - 1];
				}
			}
		}
		int m = in.nextInt();
		while (m-- > 0) {
			int x = in.nextInt();
			int y = in.nextInt();
			x--; y--;
			out.println(dp[x][y] ? 1 : 0);
		}
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
