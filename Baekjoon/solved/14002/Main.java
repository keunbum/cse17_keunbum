import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int[] dp = new int[n];
		int[] p = new int[n];
		Arrays.fill(p, -1);
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					p[i] = j;
				}
			}
		}
		int x = 0;
		for (int i = 1; i < n; i++) {
			if (dp[x] < dp[i]) {
				x = i;
			}
		}
		out.println(dp[x]);
		Stack<Integer> ans = new Stack<>();
		while (x != -1) {
			ans.push(a[x]);
			x = p[x];
		}
		while (!ans.isEmpty()) {
			out.print(ans.pop() + " ");
		}
		out.println();
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
