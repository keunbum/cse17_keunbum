import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int tt = in.nextInt();
		while (tt-- > 0) {
			int qq = in.nextInt();
			int m = in.nextInt();
			out.println(qq + " " + m + (isPrime(m) && isHappy(m) ? " YES" : " NO"));
		}
	}

	boolean isPrime(int n) {
		if (n < 2) return false;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}

	boolean isHappy(int m) {
		Set<Integer> was = new HashSet<>();
		do {
			was.add(m);
			int t = 0;
			while (m > 0) {
				t += (m % 10) * (m % 10);
				m /= 10;
			}
			m = t;	
		} while (!was.contains(m));
		return m == 1;
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
