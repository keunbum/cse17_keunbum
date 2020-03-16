import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	int dfs(int v, int[] dp, int[] cost, List<Integer>[] graph) {
		if (dp[v] >= 0) return dp[v];
		int max = 0;
		for (int u : graph[v]) {
			max = Math.max(max, dfs(u, dp, cost, graph));
		}  
		return dp[v] = max + cost[v];
	}

	void solve() {
		int tt = in.nextInt();
		while (tt-- > 0) {
			int n = in.nextInt();
			int k = in.nextInt();
			int[] cost = new int[n];
			int[] dp = new int[n];
			List<Integer>[] graph = new List[n];
			for (int i = 0; i < n; i++) {
				cost[i] = in.nextInt();
				dp[i] = -1;
				graph[i] = new ArrayList<>();
			}
			while (k-- > 0) {
				int x = in.nextInt() - 1;
				int y = in.nextInt() - 1;
				graph[y].add(x);
			}
			int w = in.nextInt() - 1;
			out.println(dfs(w, dp, cost, graph));
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
