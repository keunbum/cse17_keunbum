import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		final int N = (int) 1e6;
		boolean[] is_c = new boolean[N + 1];
		for (int i = 2; i <= N; i++) {
			if (is_c[i]) continue;
			for (int j = i + i; j <= N; j += i) is_c[j] = true;
		}
		while (true) {
			int n = in.nextInt();
			if (n == 0) break;
			for (int i = 3; i <= n / 2; i += 2) {
				int j = n - i;
				if (!is_c[i] && !is_c[j]) {
					out.println(n + " = " + i + " + " + j);
					break;
				}
			}
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
