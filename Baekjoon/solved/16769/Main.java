import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	int[] m;
	int[] c;
	void solve() {
		m = new int[3];
		c = new int[3];
		for (int i = 0; i < 3; i++) {
			c[i] = in.nextInt();
			m[i] = in.nextInt();
		}
		for (int i = 0; i < 33; i++) {
			pour(0, 1);
			pour(1, 2);
			pour(2, 0);
		}
		pour(0, 1);
		for (int i = 0; i < 3; i++) out.println(m[i]);
	}

	void pour(int x, int y) {
		int z = Math.min(m[x], c[y] - m[y]);
		m[x] -= z;
		m[y] += z;
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
