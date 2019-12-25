import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		while (true) {
			int n = in.nextInt();
			if (n == -1) {
				break;
			}
			List<Integer> a = new ArrayList<>();
			a.add(1);
			for (int i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					a.add(i);
					if (i * i != n) {
						a.add(n / i);
					}
				}
			}
			Collections.sort(a);
			int sum = 0;
			for (int x : a) {
				sum += x;
			}
			if (sum == n) {
				out.print(n + " = ");
				int m = a.size();
				for (int i = 0; i < m; i++) {
					if (i > 0) {
						out.print(" + ");
					}
					out.print(a.get(i));
				}
				out.println();
			} else {
				out.println(n + " is NOT perfect.");				
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
