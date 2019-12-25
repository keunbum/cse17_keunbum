import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		int tt = in.nextInt();
		solver.solve(tt, in, out);
		out.close();
	}
	
	static class Task {
		public void solve(int tt, InputReader in, PrintWriter out) {
			while (tt-- > 0) {
				int n = in.nextInt();
				int[] a = new int[n];
				for (int i = 0; i < n; i++) {
					a[i] = in.nextInt();
				}
				long ans = 0;
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						ans += gcd(a[i], a[j]);
					}
				}
				out.println(ans);
			}
		}
		public int gcd(int a, int b) {
			while (a > 0) {
				int t = b % a;
				b = a;
				a = t;
			}
			return b;
		}
	}
	
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		
		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
		  tokenizer = null;
		}
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
