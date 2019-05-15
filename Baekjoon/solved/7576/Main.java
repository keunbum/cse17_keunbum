import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int m = in.nextInt();
      int n = in.nextInt();
      int cnt0 = 0;
      Queue<TaskA.Point> que = new LinkedList<TaskA.Point>();
      TaskA.Point[] v = new TaskA.Point[] {new TaskA.Point(1, 0), new TaskA.Point(0, 1), new TaskA.Point(-1, 0), new TaskA.Point(0, -1)};
      int[][] a = new int[n][m];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = in.nextInt();
          if (a[i][j] == 1) que.offer(new TaskA.Point(i, j)); else
          if (a[i][j] == 0) cnt0++;
        }
      }
      int day = 1;
      while (!que.isEmpty()) {
        TaskA.Point tmp = new TaskA.Point(que.peek());
        que.poll();
        for (int i = 0; i < 4; i++) {
          TaskA.Point nn = new TaskA.Point(tmp.plus(v[i]));
          if (nn.x < 0 || nn.x >= n || nn.y < 0 || nn.y >= m || a[nn.x][nn.y] != 0) continue;
          que.offer(nn);
          day = a[nn.x][nn.y] = a[tmp.x][tmp.y] + 1;
          cnt0--;
        }
      }
      if (cnt0 > 0) day = 0;
      out.println(day - 1);
    }

    static class Point {
      int x, y;

      public Point(int x, int y) {
        this.x = x;
        this.y = y;
      }

      public Point(Point x) {
        this(x.x, x.y);
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