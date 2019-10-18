import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	class Pair implements Comparable<Pair> {
		int first, second;
		public Pair(int _first, int _second) {
			this.first = _first;
			this.second = _second;
		}
		public int compareTo(Pair o) {
			return Integer.compare(o.first, this.first);
		}
	}
	
	int Get(int x, int y) {
		if (y == 0) return x + 1;
		return x * (y + 1);
	}
	
	void solve() {
		final int INF = (int) 1e9;
		int n = in.nextInt();
		PriorityQueue<Pair> s = new PriorityQueue<>();
		int[] dist = new int[n + 1];
		Arrays.fill(dist, INF);
		dist[1] = 0;
		s.offer(new Pair(dist[1], 1));
		int[] p = new int[n + 1];
		while (!s.isEmpty()) {
			int i = s.peek().second;
			int expected = s.poll().first;
			if (dist[i] != expected) {
				continue;
			}
			for (int j = 0; j < 3; j++) {
				int u = Get(i, j);
				if (u <= n && dist[u] > dist[i] + 1) {
					dist[u] = dist[i] + 1;
					s.offer(new Pair(dist[u], u));
					p[u] = i;
				}
			}
		}
		out.println(dist[n]);
		while (n != 1) {
			out.print(n + " ");
			n = p[n];
		}
		out.println(1);
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
