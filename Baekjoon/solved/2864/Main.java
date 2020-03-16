import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int min = a + b;
		int max = a + b;
		int e = 1;
		while (a > 0 && b > 0) {
			int A = a % 10;
			int B = b % 10;
			if (A == 5) max += e; else
			if (A == 6) min -= e;
			if (B == 5) max += e; else
			if (B == 6) min -= e;
			a /= 10;
			b /= 10;
			e *= 10;
		}
		out.println(min + " " + max);
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
