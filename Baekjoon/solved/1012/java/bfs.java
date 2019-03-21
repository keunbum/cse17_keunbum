import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    TaskA solver = new TaskA();
    int tt = in.nextInt();
    solver.solve(tt, in, out);
    out.close();
  }

  static class TaskA {
    static int cnt;
    static TaskA.Point[] v = new TaskA.Point[] {new TaskA.Point(1, 0), new TaskA.Point(0, 1), new TaskA.Point(-1, 0), new TaskA.Point(0, -1)};
    static int[][] a;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      while (testNumber-- > 0) {
        int w = in.nextInt();
        int h = in.nextInt();
        int n = in.nextInt();
        cnt = 0;
        a = new int[h][w];
        while (n-- > 0) {
          int y = in.nextInt();
          int x = in.nextInt();
          a[x][y] = 1;
        }
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            bfs(h, w, i, j);
          }
        }
        out.println(cnt);
      }
    }

    private void bfs(int h, int w, int x, int y) {
      if (!isOk(h, w, x, y))
        return;
      cnt++; 
      a[x][y] = 0;
      TaskA.Point[] que = new TaskA.Point[50 * 50 * 4];
      int f, r = 0;
      que[r++] = new TaskA.Point(x, y);
      for (f = 0; f < r; f++) {
        TaskA.Point c = que[f];
        for (int i = 0; i < 4; i++) {
          TaskA.Point n = c.plus(v[i]);
          if (isOk(h, w, n.x, n.y)) {
            a[n.x][n.y] = 0;
            que[r++] = n;
          }
        }
      }
    }

    private boolean isOk(int h, int w, int x, int y) {
      return (x >= 0 && x < h && y >= 0 && y < w && a[x][y] != 0);
    }

    static class Point {
      int x, y;
      
      public Point(int x, int y) {
        this.x = x;
        this.y = y;
      }

      public Point plus(Point b) {
        return new Point(this.x + b.x, this.y + b.y);
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