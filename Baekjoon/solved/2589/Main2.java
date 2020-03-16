import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int[] DX = {1, 0, -1, 0};
	static final int[] DY = {0, 1, 0, -1};

	class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
		
	void solve() {
		int h = in.nextInt();
		int w = in.nextInt();
		char[][] s = new char[h][];
		for (int i = 0; i < h; i++) s[i] = in.next().toCharArray();
		int ans = 0;
		int[][] dist = new int[h][w];
		Queue<Point> que = new ArrayDeque<>();
		for (int sx = 0; sx < h; sx++) {
			for (int sy = 0; sy < w; sy++) {
				if (s[sx][sy] == 'W') continue;
				for (int i = 0; i < h; i++) Arrays.fill(dist[i], -1);
				dist[sx][sy] = 0;
				que.offer(new Point(sx, sy));
				while (!que.isEmpty()) {
					Point p = que.poll();
					for (int dir = 0; dir < 4; dir++) {
						int nx = p.x + DX[dir];
						int ny = p.y + DY[dir];
						if (nx < 0 || ny < 0 || nx >= h || ny >= w || s[nx][ny] != 'L' || dist[nx][ny] != -1) continue;
						dist[nx][ny] = dist[p.x][p.y] + 1;
						que.offer(new Point(nx, ny));
						ans = Math.max(ans, dist[nx][ny]);
					}
				}
			}
		}
		out.println(ans);
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
