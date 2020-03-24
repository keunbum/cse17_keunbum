import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final long INF = (long) 1e18;

	int n;
	int[] x;
	int[] y;

	long dfs(int balance, int depth, long vx, long vy) {
		if (depth == n) {
			if (balance == 0) {
				return vx * vx + vy * vy;
			}	
			return INF;
		}
		long res = dfs(balance, depth + 1, vx + x[depth], vy + y[depth]);
		if (balance > 0) res = Math.min(res, dfs(balance - 1, depth + 1, vx - x[depth], vy - y[depth]));
		return res;
	}

	void solve() {
		int tt = in.nextInt();
		while (tt-- > 0) {
			n = in.nextInt();
			x = new int[n];
			y = new int[n];
			for (int i = 0; i < n; i++) {
				x[i] = in.nextInt();
				y[i] = in.nextInt();
			}
			out.println(Math.sqrt(dfs(n / 2, 0, 0, 0)));
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

		public String nextLn() {
			try {
				return br.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}	
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
