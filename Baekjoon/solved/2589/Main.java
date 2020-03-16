import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int h = in.nextInt();
		int w = in.nextInt();
		char[][] s = new char[h][];
		for (int i = 0; i < h; i++) {
			s[i] = in.next().toCharArray();
		}
		int ans = 0;
		int[][] dist = new int[h][w];
		int[] qx = new int[h * w];
		int[] qy = new int[h * w];
		for (int sx = 0; sx < h; sx++) {
			for (int sy = 0; sy < w; sy++) {
				if (s[sx][sy] == 'W') continue;
				for (int i = 0; i < h; i++) Arrays.fill(dist[i], -1);
				int b = 0;
				int e = 1;
				qx[0] = sx;
				qy[0] = sy;
				dist[sx][sy] = 0;
				while (b < e) {
					for (int dir = 0; dir < 4; dir++) {
						int nx = qx[b] + "2101".charAt(dir) - '1';
						int ny = qy[b] + "1210".charAt(dir) - '1';
						if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] == 'L' && dist[nx][ny] == -1) {
							dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
							qx[e] = nx;
							qy[e] = ny;
							++e;
						}	
					}
					++b;
				}
				ans = Math.max(ans, dist[qx[b - 1]][qy[b - 1]]);
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
