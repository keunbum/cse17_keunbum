import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.ArrayDeque;

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
      int n = in.nextInt();
      int[][] a = new int[n][n];
      int x = 0, y = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a[i][j] = in.nextInt();
          if (a[i][j] == 9) {
            a[i][j] = 0;
            x = i;
            y = j;
          }
        }
      }
      int ans = 0, me = 2, cnt = 0;
      while (true) {
        int[][] dis = new int[n][n];
        for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
            dis[i][j] = -1;
        dis[x][y] = 0;
        Queue<Point> que = new ArrayDeque<Point>();
        que.offer(new Point(x, y));
        while (!que.isEmpty()) {
          Point c = que.poll();
          for (int i = 0; i < 4; i++) {
            Point t = new Point(c.x + "2101".charAt(i) - '1', c.y + "1210".charAt(i) - '1');
            if (t.x < 0 || t.x >= n || t.y < 0 || t.y >= n || a[t.x][t.y] > me || dis[t.x][t.y] != -1) continue;
            dis[t.x][t.y] = dis[c.x][c.y] + 1;
            que.offer(t);
          }
        }
        int min = 1 << 30;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (dis[i][j] != -1 && a[i][j] > 0 && a[i][j] < me) {
              if (dis[i][j] < min) {
                min = dis[i][j];
                x = i;
                y = j;
              }
            }
          }
        }
        if (min == 1 << 30) break;
        ans += dis[x][y];
        a[x][y] = 0;
        if (++cnt == me) {
          me++;
          cnt = 0;
        }
      }
      out.println(ans);
    }
    static class Point {
      int x, y;
      public Point(int x, int y) {
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