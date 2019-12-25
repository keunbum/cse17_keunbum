import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
		int n = in.nextInt();
		String[] who = new String[n];
		int[] delta = new int[n];
		Map<String, Integer> map = new HashMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			who[i] = in.next();
			delta[i] = in.nextInt();
			map.put(who[i], map.containsKey(who[i]) ? map.get(who[i]) + delta[i] : delta[i]);
		}
		int max = 0;
		for (Integer x : map.values()) {
			max = Math.max(max, x);
		}
		Set<String> possible = new HashSet<String>();
		for (Map.Entry<String, Integer> entry : map.entrySet()) {
			if (entry.getValue() == max) {
				possible.add(entry.getKey());
			}
		}
		map.clear();
		String ans = null;
		for (int i = 0; i < n; i++) {
			map.put(who[i], map.containsKey(who[i]) ? map.get(who[i]) + delta[i] : delta[i]);
			if (map.get(who[i]) >= max && possible.contains(who[i])) {
				ans = who[i];
				break;
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
