import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	int[] q = new int[123];
	void solve() {
		int n = in.nextInt();
		int[] a = new int[n + 1];
		int[] deg = new int[n + 1];
		Arrays.fill(deg, 0);
		for (int i = 1; i <= n; i++) {
			a[i] = in.nextInt();
			deg[a[i]]++;
		}
		int b = 0, e = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) {
				q[e++] = i;
			}
		}
		while (b < e) {
			int x = q[b++];
			if (--deg[a[x]] == 0) {
				q[e++] = a[x];
			}
		}
		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = 1; i <= n; i++) {
			if (deg[i] > 0) {
				ans.add(i);
			}
		}
		out.println(ans.size());
		for (int x : ans) {
			out.println(x);
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
