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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int[][] a = new int[n + 2][n + 2];
      Point[] b = new Point[n * n];
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          a[i][j] = in.nextInt();
          b[(i - 1) * n + j - 1] = new Point(i, j);
        }
      }
      Arrays.sort(b, new Comparator<Point>() {
        public int compare(Point u, Point v) {
          return a[u.x][u.y] - a[v.x][v.y];
        }
      });
      int[][] dp = new int[n + 2][n + 2];
      dp[b[0].x][b[0].y] = 1;
      int ans = 1;
      for (Point t : b) {
        int x = t.x;
        int y = t.y;
        dp[x][y] = 1;
        for (int i = 0; i < 4; i++) {
          int u = x + "2101".charAt(i) - '1';
          int v = y + "1210".charAt(i) - '1';
          if (a[u][v] < a[x][y]) {
            dp[x][y] = Math.max(dp[x][y], dp[u][v] + 1);
            ans = Math.max(ans, dp[x][y]);
          }
        }
      }
      out.println(ans);
    }
    static class Point {
      int x, y;
      Point(int x, int y) {
        this.x = x;
        this.y = y;
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