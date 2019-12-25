import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
	class Student {
		String s;
		int x, y, z;
		
		public Student(String s, int x, int y, int z) {
			this.s = s;
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
	void solve() {
		int n = in.nextInt();
		List<Student> a = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			a.add(new Student(in.next(), in.nextInt(), in.nextInt(), in.nextInt()));
		}
		Collections.sort(a, new Comparator<Student>() {
			public int compare(Student p, Student q) {
				int t = Integer.compare(q.x, p.x);
				if (t != 0) return t;
				t = Integer.compare(p.y, q.y);
				if (t != 0) return t;
				t = Integer.compare(q.z, p.z);
				if (t != 0) return t;
				return p.s.compareTo(q.s); 
			}	
		});
		for (int i = 0; i < n; i++) {
			out.println(a.get(i).s);
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
