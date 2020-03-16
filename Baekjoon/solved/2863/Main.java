import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	class Fraction {
		int x;
		int y;
		int id;

		public Fraction(int a, int b, int c, int d, int id) {
			this.x = a * d + b * c;
			this.y = c * d;
			this.id = id;
		}
	}

	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		List<Fraction> f = new ArrayList<>();
		f.add(new Fraction(a, b, c, d, 0));
		f.add(new Fraction(c, a, d, b, 1));
		f.add(new Fraction(d, c, b, a, 2));
		f.add(new Fraction(b, d, a, c, 3));
		Collections.sort(f, new Comparator<Fraction>() {
			public int compare(Fraction n1, Fraction n2) {
				return n1.x * n2.y - n2.x * n1.y;
			}
		});
		out.println(f.get(3).id);
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
