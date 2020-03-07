import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		while (true) {
			List<Integer> a = new ArrayList<>();
			while (true) {
				int t = in.nextInt();
				if (t == -1) return;
				if (t == 0) break;
				a.add(t);
			}
			int ans = 0;
			int n = a.size();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a.get(i) * 2 == a.get(j)) ++ans;
				}
			}	
			out.println(ans);
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
