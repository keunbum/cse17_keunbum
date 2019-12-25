import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[][] a = new int[n][n];
      int dir = 0;
      int x = 0;
      int y = 0;
      for (int i = n * n; i > 0; i--) {
        a[x][y] = i;
        int u = x + "2101".charAt(dir) - '1';
        int v = y + "1210".charAt(dir) - '1';
        if (u < 0 || u >= n || v < 0 || v >= n || a[u][v] > 0) {
          dir = (++dir) & 3;
        }
        x += "2101".charAt(dir) - '1';
        y += "1210".charAt(dir) - '1';
      }
      int p = 0;
      int q = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          out.print(a[i][j] + " ");
          if (a[i][j] == k) {
            p = i + 1;
            q = j + 1;
          }
        }
        out.println();
      }
      out.println(p + " " + q);
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