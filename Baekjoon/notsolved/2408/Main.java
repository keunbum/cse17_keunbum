import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	BigInteger operate(BigInteger a, BigInteger b, String type) {
		if (type == "+") return a.add(b);
		if (type == "-") return a.subtract(b);
		if (type == "*") return a.multiply(b);
		if (type == "/") return a.divide(b);
		return BigInteger.valueOf(-1);
	}
	void solve() {
		int n = in.nextInt();
		BigInteger ans = BigInteger.ZERO;
		String type = "+";
		for (int i = 0; i < n + n - 1; i++) {
			if (i % 2 == 0) {
				BigInteger foo = new BigInteger(in.next());
				ans = operate(ans, foo, type);
			} else {
				type = in.next();
			}
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
