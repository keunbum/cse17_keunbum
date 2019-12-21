import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int inf = (int) 1e9;
	void solve() {
		int n = in.nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = inf;
			}
		}
		int m = in.nextInt();
		while (m-- > 0) {
			int x = in.nextInt();
			int y = in.nextInt();
			x--; y--;
			a[x][y] = a[y][x] = 1;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
		int mn = inf, mi = 0;
		for (int i = 0; i < n; i++) {
			int foo = 0;
			for (int j = 0; j < n; j++) {
				if (i != j) {
					foo += a[i][j];
				}
			}
			if (foo < mn) {
				mn = foo;
				mi = i;
			}
		}
		out.println(++mi);
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
