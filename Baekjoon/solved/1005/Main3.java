import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	class Vertex {
		int v_id;
		int cost;
		int totalCost;
		int deg;
		List<Vertex> adj = new ArrayList<>();
	}
		
	void solve() {
		int tt = in.nextInt();
		while (tt-- > 0) {
			int n = in.nextInt();
			int k = in.nextInt();
			Vertex[] vs = new Vertex[n];
			for (int i = 0; i < n; i++) {
				vs[i] = new Vertex();
				vs[i].v_id = i;
				vs[i].cost = in.nextInt();
				vs[i].totalCost = 0;
				vs[i].deg = 0;
			}
			while (k-- > 0) {
				Vertex a = vs[in.nextInt() - 1];
				Vertex b = vs[in.nextInt() - 1];
				a.adj.add(b);
				++b.deg;
			}
			int[] q = new int[n];
			int b = 0;
			int e = 0;
			for (int id = 0; id < n; id++) {
				if (vs[id].deg == 0) {
					vs[id].totalCost += vs[id].cost;
					q[e] = id;
					++e;
				}
			}
			while (b < e) {
				Vertex v = vs[q[b]];
				for (Vertex u : v.adj) {
					u.totalCost = Math.max(u.totalCost, v.totalCost);
					if (--u.deg == 0) {
						u.totalCost += u.cost;
						q[e] = u.v_id;
						++e;
					}	
				}
				++b;
			}
			int w = in.nextInt() - 1;
			out.println(vs[w].totalCost);
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
