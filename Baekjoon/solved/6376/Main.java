import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	void solve() {
	  out.println("n e");
	  out.println("- -----------");
	  out.println("0 1");
	  out.println("1 2");
	  out.println("2 2.5");
	  double acc = 2.5;
	  int fac = 2;
	  for (int i = 3; i < 10; i++) {
	    fac *= i;
	    acc += 1.0 / fac;
	    out.println(String.format("%d %.9f", i, acc));
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
