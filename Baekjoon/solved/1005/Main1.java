import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	class Vertex {
		int cost;
		int totalCost;
		List<Vertex> adj = new ArrayList<>();

		int dfs() {
			if (totalCost >= 0) return totalCost;
			int max = 0;
			for (Vertex u : adj) {
				max = Math.max(max, u.dfs());
			}
			return totalCost = max + cost;
		}
	}
		
	void solve() {
		int tt = in.nextInt();
		while (tt-- > 0) {
			int n = in.nextInt();
			int k = in.nextInt();
			Vertex[] vs = new Vertex[n];
			for (int i = 0; i < n; i++) {
				vs[i] = new Vertex();
				vs[i].cost = in.nextInt();
				vs[i].totalCost = -1;
			}	
			while (k-- > 0) {
				Vertex a = vs[in.nextInt() - 1];
				Vertex b = vs[in.nextInt() - 1];
				b.adj.add(a);
			}
			int w = in.nextInt() - 1;
			out.println(vs[w].dfs());
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
