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
    static PrintWriter out;
    static int n, m;
    static int[] a, v;
    public void solve(int testNumber, InputReader in, PrintWriter _out) {
      out = _out;
      n = in.nextInt();
      m = in.nextInt();
      a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      Arrays.sort(a);
      v = new int[n];
      dfs(0, 0);
    }
    private void dfs(int x, int pos) {
      if (x == m) {
        for (int i = 0; i < m; i++) {
          out.print((i > 0 ? " " : "") + v[i]);
        }
        out.println();
        return;
      }
      for (int i = pos; i < n; i++) {
        v[x] = a[i];
        dfs(x + 1, i + 1);
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