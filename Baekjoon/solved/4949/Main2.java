import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		while (true) {
			char[] s = in.nextLn().toCharArray();
			if (s[0] == '.') break;
			Stack<Character> st = new Stack<>();
			boolean ok = true;
			for (char c : s) {
				if (c == '(' || c == '[') st.push(c); else
				if (c == ')') {
					if (st.empty() || st.peek() != '(') { ok = false; break; }
					st.pop();
				} else
				if (c == ']') {
					if (st.empty() || st.peek() != '[') { ok = false; break; }
					st.pop();
				}
			}
			if (!st.empty()) ok = false;
			out.println(ok ? "yes" : "no");
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
