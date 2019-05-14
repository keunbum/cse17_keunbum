import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;

public class Main {
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      int[][] a = new int[n + 2][m + 2];
      for (int i = 1; i <= n; i++) {
        String s = "0" + in.next();
        for (int j = 1; j <= m; j++) {
          a[i][j] = s.charAt(j) - '0';
        }
      }
      List<Point> que = new ArrayList<>();
      que.add(new Point(1, 1));
      a[1][1] = 2;
      for (int i = 0; i < que.size(); i++) {
        int cx = que.get(i).x;
        int cy = que.get(i).y;
        if (a[cx][cy] == a[n][m]) break;
        for (int j = 0; j < 4; j++) {
          int x = cx + "2101".charAt(j) - '1';
          int y = cy + "1210".charAt(j) - '1';
          if (a[x][y] != 1) continue;
          a[x][y] = a[cx][cy] + 1;
          que.add(new Point(x, y));
        }
      }
      out.println(a[n][m] - 1);
    }
  }
  static class Point {
    int x;
    int y;
    public Point(int a, int b) {
      x = a;
      y = b;
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