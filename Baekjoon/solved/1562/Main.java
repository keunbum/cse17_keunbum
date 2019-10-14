import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int MD = (int) 1e9;
	
	int add(int a, int b) {
		a += b;
		if (a >= MD) a -= MD;
		return a;
	}
	
	void solve() {
		int n = in.nextInt();
		int[][][] dp = new int [n + 1][10][1 << 10];
		for (int i = 1; i < 10; i++) {
			dp[1][i][1 << i] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				for (int t = 1; t < (1 << 10); t++) {
					if (j - 1 >= 0 && (t & (1 << (j - 1))) != 0) {
						dp[i][j][t | (1 << j)] = add(dp[i][j][t | (1 << j)], dp[i - 1][j - 1][t]);
					}
					if (j + 1 < 10 && (t & (1 << (j + 1))) != 0) {
						dp[i][j][t | (1 << j)] = add(dp[i][j][t | (1 << j)], dp[i - 1][j + 1][t]);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			ans = add(ans, dp[n][i][(1 << 10) - 1]);
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
