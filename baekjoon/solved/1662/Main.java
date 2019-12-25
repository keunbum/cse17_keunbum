import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int N = 55;
	void solve() {
		char[] s = in.next().toCharArray();
		int[] stk = new int[N];
		char[] stk_c = new char[N];
		int top = 0;
		for (char c : s) {
			if (c != ')') {
				stk[top] = (c == '(' ? -1 : 1);
				stk_c[top] = c;
				top++;
			} else {
				int v = 0;
				while (stk_c[--top] != '(') {
					v += stk[top];
				}
				stk[top - 1] = (stk_c[top - 1] - '0') * v;
			}
		}
		int ans = 0;
		while (--top >= 0) {
			ans += stk[top];
		}
		out.println(ans);
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
