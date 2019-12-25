import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	boolean[] was;
	ArrayList<Integer>[] g, g_rev;
	Stack<Integer> order;
	int[] c;
	private int To(int x) {
		int res = ((Math.abs(x) - 1) << 1) + (x < 0 ? 1 : 0);
		return res;
	}
	void Dfs1(int v) {
		was[v] = true;
		for (int u : g[v]) {
			if (!was[u]) {
				Dfs1(u);
			}
		}
		order.add(v);
	}
	void Dfs2(int v) {
		for (int u : g_rev[v]) {
			if (c[u] == -1) {
				c[u] = c[v];
				Dfs2(u);
			}
		}
	}
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		g = new ArrayList[n + n];
		g_rev = new ArrayList[n + n];
		for (int i = 0; i < n + n; i++) {
			g[i] = new ArrayList();
			g_rev[i] = new ArrayList();
		}
		while (m-- > 0) {
			int foo = in.nextInt();
			int bar = in.nextInt();
			int x = To(foo);
			int y = To(bar);
			g[x ^ 1].add(y);
			g_rev[y].add(x ^ 1);
			g[y ^ 1].add(x);
			g_rev[x].add(y ^ 1);
		}
		was = new boolean[n + n];
		Arrays.fill(was, false);
		order = new Stack<>();
		for (int i = 0; i < n + n; i++) {
			if (!was[i]) {
				Dfs1(i);
			}
		}
		int cnt = 0;
		c = new int[n + n];
		Arrays.fill(c, -1);
		while (!order.isEmpty()) {
			int v = order.pop();
			if (c[v] == -1) {
				c[v] = cnt++;
				Dfs2(v);
			}
		}
		boolean ok = true;
		for (int i = 0; i < n + n; i += 2) {
			if (c[i] == c[i ^ 1]) {
				ok = false;
				break;
			}
		}
		out.println(ok ? 1 : 0);
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
