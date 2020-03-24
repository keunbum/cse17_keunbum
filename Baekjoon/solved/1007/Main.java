import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	int bitCount(int set) {
		int res = 0;
		while (set > 0) {
			++res;
			set &= set - 1;
		}
		return res;
	}
		
	void solveOne() {
		int n = in.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		long ans = (long) 1e18;
		for (int set = 0; set < (1 << n); set++) {
			if (bitCount(set) * 2 != n) continue;
			long vx = 0;
			long vy = 0;
			for (int i = 0; i < n; i++) {
				if (((set >> i) & 1) == 1) {
					vx += x[i];
					vy += y[i];
				} else {
					vx -= x[i];
					vy -= y[i];
				}	
			}
			ans = Math.min(ans, vx * vx + vy * vy);
		}
		out.print(String.format("%.17f\n", Math.sqrt(ans)));	
	}

	void solve() {
		int testNum = in.nextInt();
		while (testNum-- > 0) {
			solveOne();
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
