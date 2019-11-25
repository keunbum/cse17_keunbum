import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	boolean isHan(int n) {
		if (n < 100) {
			return true;
		}
		int a = n / 100;
		int b = (n / 10) % 10;
		int c = n % 10;
		return b + b == a + c;
	}
	
	void solve() {
		int n = in.nextInt();
		int ans = 0;
		while (n > 0) {
			ans += isHan(n--) ? 1 : 0;
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
