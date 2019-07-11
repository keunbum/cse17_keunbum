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
    static int n, m;
    static int[] v;
    static boolean[] chk;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      n = in.nextInt();
      m = in.nextInt();
      v = new int[n + 1];
      chk = new boolean[n + 1];
      dfs(0, out);
    }
    public void dfs(int x, PrintWriter out) {
      if (x == m) {
        for (int i = 0; i < m; i++) {
          out.print((i > 0 ? " " : "") + v[i]);
        }
        out.println();
        return;
      }
      for (v[x] = 1; v[x] <= n; v[x]++) {
        if (chk[v[x]]) continue;
        chk[v[x]] = true;
        dfs(x + 1, out);
        chk[v[x]] = false; 
      }
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