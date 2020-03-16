import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	class Fraction {
		int x;
		int y;

		public Fraction(int a, int b, int c, int d) {
			this.x = a * d + b * c;
			this.y = c * d;
		}
	}

	int compare(Fraction a, Fraction b) {
		return a.x * b.y - b.x * a.y;
	}	

	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		List<Fraction> f = new ArrayList<>();
		f.add(new Fraction(a, b, c, d));
		f.add(new Fraction(c, a, d, b));
		f.add(new Fraction(d, c, b, a));
		f.add(new Fraction(b, d, a, c));
		int cur_i = 0;
		for (int i = 1; i < 4; i++) {
			if (compare(f.get(cur_i), f.get(i)) < 0) {
				cur_i = i;
			}	
		}
		out.println(cur_i);
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
