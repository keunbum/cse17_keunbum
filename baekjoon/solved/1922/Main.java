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
    static int[] p;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      p = new int[n];
      Queue<Edge> edge = new PriorityQueue<>();
      while (m-- > 0) {
        edge.offer(new Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
      }
      for (int i = 0; i < n; i++) p[i] = i;
      int ans = 0;
      for (int i = 0; i < n - 1; i++) {
        Edge e = null;
        do {
          e = edge.poll();
        } while (get(e.from) == get(e.to));
        p[get(e.from)] = get(e.to);
        ans += e.cost;
      }
      out.println(ans);
    }
    static class Edge implements Comparable<Edge> {
      int from, to, cost;
      public Edge(int f, int t, int c) {
        from = f;
        to = t;
        cost = c;
      }
      public int compareTo(Edge other) {
        return cost - other.cost;
      }
    }
    public int get(int x) {
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