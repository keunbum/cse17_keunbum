import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	int n;
	int[][] a;
	BigInteger[][] dp;
	
	BigInteger dfs(int x, int y) {
		if (dp[x][y].compareTo(BigInteger.ZERO) >= 0) {
			return dp[x][y];
		}
		BigInteger res = BigInteger.ZERO;
		if (x + a[x][y] < n) {
			res = res.add(dfs(x + a[x][y], y));
		}
		if (y + a[x][y] < n) {
			res = res.add(dfs(x, y + a[x][y]));
		}
		return dp[x][y] = res;
	}
	
	void solve() {
		n = in.nextInt();
		a = new int[n][n];
		dp = new BigInteger[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp[i], BigInteger.ONE.negate());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = in.nextInt();
				if (a[i][j] == 0) {
					dp[i][j] = BigInteger.ZERO;
				}
			}
		}
		dp[n - 1][n - 1] = BigInteger.ONE;
		out.println(dfs(0, 0));
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
