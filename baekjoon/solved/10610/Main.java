import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int[] cnt = new int[128];
		String s = in.next();
		int foo = 0;
		for (char c : s.toCharArray()) {
			cnt[c]++;
			foo += (c - '0');
		}
		if (cnt['0'] <= 0 || (foo % 3 != 0)) {
			out.println("-1");
			return;
		}
		StringBuilder ans = new StringBuilder();
		for (char c = '9'; c >= '0'; c--) {
			int t = cnt[c];
			while (t-- > 0) ans.append(c);
		}
		out.println(ans.toString());
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
