import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	int[] a;
	int[] p;
	void print(int i) {
		if (p[i] != -1) {
			print(p[i]);
		}
		out.print(a[i] + " ");
	}
	int binarySearch(int[] b, int n, int i) {
		int low = 0;
		int high = n;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (a[b[mid]] < a[i]) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low;
	}
	void solve() {
		int n = in.nextInt();
		a = new int[n];
		int[] b = new int[n];
		p = new int[n];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			int k = binarySearch(b, cnt, i);
			b[k] = i;
			p[b[k]] = k > 0 ? b[k - 1] : -1;
			if (k == cnt) {
				cnt++;
			}
		}
		out.println(cnt);
		print(b[cnt - 1]);
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
