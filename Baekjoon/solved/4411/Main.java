import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		while (true) {
			int n = in.nextInt();
			if (n == 0) {
				break;
			}
			int[] a = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++) {
				float f = in.nextFloat();
				a[i] = (int) (f * 100 + 0.5);
				sum += a[i];
			}
			Arrays.sort(a);
			int q = sum / n;
			int r = sum % n;
			int ans = 0;
			for (int i = n - 1; i >= 0; i--) {
				int v = q;
				if (i > n - 1 - r) v++;
				ans += Math.abs(a[i] - v);
			}
			out.println(String.format("$%.2f", ans / 200.0));
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
		
		public float nextFloat() {
			return Float.parseFloat(next());
		}
	}
 
	public static void main(String[] args) {
		new Main().run();
	}
}
