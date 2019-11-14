import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	public class Pair {
		BigInteger n;
		char type;
		Pair(BigInteger n, char type) {
			this.n = n;
			this.type = type;
		}
	}
	void solve() {
		int n = in.nextInt();
		Pair[] stk = new Pair[30];
		int top = 0;
		stk[top++] = Pair(BigInteger.ZERO, '+');
		BigInteger ans = BigInteger.ZERO;
		for (int i = 0; i < n + n - 1; i++) {
			if (i % 2 == 0) {
				BigInteger foo = new BigInteger(in.next());
				char type = stk[top - 1].type;
				if (top > 1) {
					stk[top - 1].n = cal(stk[top - 1].n, foo, type);
			} else {
				stk[top++].type = in.next().charAt(0);
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
