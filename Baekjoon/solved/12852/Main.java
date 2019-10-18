import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int n = in.nextInt();
		int[] dp = new int[n + 1];
		dp[1] = 0;
		int[] p = new int[n + 1];
		for (int i = 2; i <= n; i++) {
			int from = i - 1;
			dp[i] = dp[from] + 1;
			p[i] = from;
			from = i >> 1;
			if ((i & 1) == 0 && dp[i] > dp[from] + 1) {
				dp[i] = dp[from] + 1;
				p[i] = from;
			}
			from = i / 3;
			if (i % 3 == 0 && dp[i] > dp[from] + 1) {
				dp[i] = dp[from] + 1;
				p[i] = from;
			}
		}
		out.println(dp[n]);
		while (n != 1) {
			out.print(n + " ");
			n = p[n];
		}
		out.println(1);
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
