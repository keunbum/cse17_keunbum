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
    solver.solve(1, in, out);
    out.close();
  }
  static class Task {
    int[] p;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      p = new int[n];
      Edge[] e = new Edge[m];
      for (int i = 0; i < m; i++) {
        int x = in.nextInt();
        int y = in.nextInt();
        int z = in.nextInt();
        x--; y--;
        e[i] = new Edge(x, y, z);
      }
      for (int i = 0; i < n; i++) p[i] = i;
      Arrays.sort(e, (a, b)->{return a.cost - b.cost;});
      int ans = 0;
      for (int i = 0; i < m; i++) {
        int u = e[i].from;
        int v = e[i].to;
        u = get(u);
        v = get(v);
        if (u == v) continue;
        p[u] = v;
        ans += e[i].cost;
      }
      out.println(ans);
    }
    static class Edge {
      int from, to, cost;
      public Edge(int f, int t, int c) {
        from = f;
        to = t;
        cost = c;
      }
    }
    int get(int x) {
      return x == p[x] ? x : (p[x] = get(p[x]));
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