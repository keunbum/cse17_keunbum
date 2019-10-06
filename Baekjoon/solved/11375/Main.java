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
    static int round;
    static List<Integer>[] g;
    static int[] pa;
    static int[] pb;
    static int[] was;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      g = new List[n];
      for (int i = 0; i < n; i++) {
        g[i] = new ArrayList<>();
        int foo = in.nextInt();
        while (foo-- > 0) {
          int j = in.nextInt();
          j--;
          g[i].add(j);
        }
      }
      int ans = 0;
      round = 0;
      pa = new int[n];
      Arrays.fill(pa, -1);
      pb = new int[m];
      Arrays.fill(pb, -1);
      was = new int[n];
      while (true) {
        round++;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          if ((pa[i] == -1) && Dfs(i)) {
            cnt++;
          }
        }
        if (cnt == 0) {
          break;
        }
        ans += cnt;
      }
      out.println(ans);
    }
    public boolean Dfs(int v) {
      was[v] = round;
      for (int u : g[v]) {
        if (pb[u] == -1) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      for (int u : g[v]) {
        if (was[pb[u]] != round && Dfs(pb[u])) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      return false;
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
