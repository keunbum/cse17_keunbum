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
    static int[][] a;
    static int[] ans = new int[2];
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      a = new int[n][n];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a[i][j] = in.nextInt();
        }
      }
      dfs(0, 0, n);
      out.println(ans[0] + " " + ans[1]);
    }
    private void dfs(int x, int y, int n) {
      int t = a[x][y];
      if (n == 1) { ans[t]++; return; }
      boolean ok = true;
      for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
          if ((t ^ a[i][j]) == 1) {
            ok = false;
            i = x + n;
            break;
          }
        }
      }
      if (ok) {
        ans[t]++;
      } else {
        int s = n / 2;
        dfs(x, y, s);
        dfs(x, y + s, s);
        dfs(x + s, y, s);
        dfs(x + s, y + s, s);
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