import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int N = (int) 1e5;
	int[] a = new int[N + 1];
	int[] cnt = new int[N + 1];
	int[] q = new int[N + 1];
	void solve() {
		int st = in.nextInt();
		int en = in.nextInt();
		int b = 0, e = 0;
		a[st] = 1;
		q[e++] = st;
		cnt[st] = 1;
		while (b < e) {
			int v = q[b++];
			if (v == en) {
				break;
			}
			for (int i = -1; i <= 1; i++) {
				int u = (i == 0 ? v + v : v + i);
				if (u >= 0 && u <= N) {
					if (a[u] == 0) {
						a[u] = a[v] + 1;
						q[e++] = u;
					}
					if (a[u] == a[v] + 1) {
						cnt[u] += cnt[v];
					}
				}
			}
		}
		out.println(a[en] - 1);
		out.println(cnt[en]);
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
