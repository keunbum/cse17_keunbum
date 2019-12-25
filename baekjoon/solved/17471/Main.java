import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	boolean[] was;
	int[] c;
	List<Integer>[] g;
	void dfs(int v) {
		was[v] = true;
		for (int u : g[v]) {
			if (!was[u] && c[u] == c[v]) {
				dfs(u);
			}
		}
	}
	void solve() {
		int n = in.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = in.nextInt();
		}
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
			int t = in.nextInt();
			while (t-- > 0) {
				int j = in.nextInt();
				j--;
				g[i].add(j);
			}
		}
		final int inf = (int) 1e9;
		int ans = inf;
		c = new int[n];
		was = new boolean[n];
		for (int t = 1; t < (1 << n) - 1; t++) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				c[i] = (t >> i) & 1;
				sum += (c[i] == 1) ? p[i] : -p[i];
			}
			int cnt = 0;
			Arrays.fill(was, false);
			for (int i = 0; i < n; i++) {
				if (!was[i]) {
					dfs(i);
					cnt++;
				}
			}
			if (cnt == 2) {
				ans = Math.min(ans, Math.abs(sum));
			}
		}
		out.println(ans == inf ? -1 : ans);
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
