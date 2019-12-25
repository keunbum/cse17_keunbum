import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	ArrayList<Integer>[] g, g_rev;
	ArrayList<Integer> order;
	boolean[] was;
	int[] c;
	
	int T(int x) {
		return (Math.abs(x) - 1) * 2 + (x < 0 ? 1 : 0);
	}
	
	void dfs1(int v) {
		was[v] = true;
		for (int u : g[v]) {
			if (!was[u]) {
				dfs1(u);
			}
		}
		order.add(v);
	}
	
	void dfs2(int v) {
		for (int u : g_rev[v]) {
			if (c[u] == -1) {
				c[u] = c[v];
				dfs2(u);
			}
		}			
	}
	
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		g = new ArrayList[n + n];
		g_rev = new ArrayList[n + n];
		for (int i = 0; i < n + n; i++) {
			g[i] = new ArrayList<>();
			g_rev[i] = new ArrayList<>();
		}
		while (m-- > 0) {
			int foo = in.nextInt();
			int bar = in.nextInt();
			int x = T(foo);
			int y = T(bar);
			g[x ^ 1].add(y);
			g_rev[y].add(x ^ 1);
			g[y ^ 1].add(x);
			g_rev[x].add(y ^ 1);
		}
		was = new boolean[n + n];
		Arrays.fill(was, false);
		order = new ArrayList<>();
		for (int i = 0; i < n + n; i++) {
			if (!was[i]) {
				dfs1(i);
			}
		}
		int cnt = 0;
		c = new int[n + n];
		Arrays.fill(c, -1);
		for (int i = n + n - 1; i >= 0; i--) {
			int v = order.get(i);
			if (c[v] == -1) {
				c[v] = cnt++;
				dfs2(v);
			}
		}
		for (int i = 0; i < n + n; i += 2) {
			if (c[i] == c[i ^ 1]) {
				out.println(0);
				return;
			}
		}
		out.println(1);
		for (int i = 0; i < n + n; i += 2) {
			if (i > 0) {
				out.print(" ");
			}
			out.print(c[i] > c[i ^ 1] ? 1 : 0);
		}
		out.println();
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
