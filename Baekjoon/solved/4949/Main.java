import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		while (true) {
			String s = in.nextLn();
			int n = s.length();
			if (n == 1) break;
			int[] st = new int[n];
			int sp = 0;
			int i;
			for (i = 0; i < n; i++) {
				char ch = s.charAt(i);
				if (ch == '[' || ch == '(') st[sp++] = ch; else
				if (ch == ']') {
					if (sp == 0 || st[sp - 1] != '[') break;
					--sp;
				} else
				if (ch == ')') {
					if (sp == 0 || st[sp - 1] != '(') break;
					--sp;
				}
			}
			out.println((i == n && sp == 0) ? "yes" : "no");
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
