import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int[] DX = {1, 0, -1, 0};
	static final int[] DY = {0, 1, 0, -1};

	class Edge implements Comparable<Edge> {
		int from;
		int to;
		int cost;

		Edge(int from, int to, int cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}

		public int compareTo(Edge o) {
			return cost - o.cost;
		}	
	}

	private boolean isIn(int x, int y, int height, int width) {
		return x >= 0 && y >= 0 && x < height && y < width;
	}	
		
	private void bfs(int[][] a, int startX, int startY) {
		int height = a.length;
		int width = a[0].length;
		int[] qx = new int[height * width];
		int[] qy = new int[height * width];
		int b = 0, e = 1;
		qx[b] = startX;
		qy[b] = startY;
		while (b < e) {
			for (int dir = 0; dir < 4; dir++) {
				int nextX = qx[b] + DX[dir];
				int nextY = qy[b] + DY[dir];
				if (isIn(nextX, nextY, height, width) && a[nextX][nextY] == -1) {
					a[nextX][nextY] = a[startX][startY];
					qx[e] = nextX;
					qy[e] = nextY;
					++e;
				}	
			}
			++b;
		}
	}

	private int get(int[] p, int v) {
		int r = v;
		while (p[r] != r) r = p[r];
		while (p[v] != r) {
			int t = p[v];
			p[v] = r;
			v = t;
		}
		return r;
	}

	void solve() {
		int height = in.nextInt();
		int width = in.nextInt();
		int[][] a = new int[height][width];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				a[i][j] = in.nextInt() - 2;
			}
		}	
		int cSize = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (a[i][j] == -1) {
					a[i][j] = cSize++;
					bfs(a, i, j);
				}
			}
		}
		List<Edge> edges = new ArrayList<>();
		for (int startX = 0; startX < height; startX++) {
			for (int startY = 0; startY < width; startY++) if (a[startX][startY] >= 0) {
				for (int dir = 0; dir < 2; dir++) {
					int nextX = startX + DX[dir];
					int nextY = startY + DY[dir];
					int bLen = 0;
					while (isIn(nextX, nextY, height, width) && a[nextX][nextY] == -2) {
						++bLen;
						nextX += DX[dir];
						nextY += DY[dir];
					}
					if (isIn(nextX, nextY, height, width) && a[startX][startY] != a[nextX][nextY] && bLen >= 2) {
						edges.add(new Edge(a[startX][startY], a[nextX][nextY], bLen));
					}	
				}
			}
		}
		Collections.sort(edges);
		int costSum = 0;
		int[] p = new int[cSize];
		for (int i = 0; i < cSize; i++) p[i] = i;
		for (Edge e : edges) {
			int x = get(p, e.from);
			int y = get(p, e.to);
			if (x != y) {
				p[x] = y;
				costSum += e.cost;
			}	
		}	
		boolean ok = true;
		int root = get(p, 0);
		for (int i = 1; i < cSize; i++) {
			if (get(p, i) != root) {
				ok = false;
				break;
			}
		}
		out.println(ok ? costSum : -1);	
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
