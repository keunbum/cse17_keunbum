import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	static final int alpha = 26;
	void solve() {
		int n = in.nextInt();
		int[] cnt = new int[alpha];
		while (n-- > 0) {
			char[] s = in.next().toCharArray();
			int e = 1;
			for (int i = s.length - 1; i >= 0; i--) {
				cnt[s[i] - 'A'] += e;
				e *= 10;
			}	
		}
		Arrays.sort(cnt);
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += cnt[i + 16] * i;
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
