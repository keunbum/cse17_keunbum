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
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {
    static int cnt;
    static int[] vx = {1, 0 , -1, 0}, vy = {0, 1, 0, -1};
    static int[][] a;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int tt = in.nextInt();
      while (tt-- > 0) {
        int w = in.nextInt();
        int h = in.nextInt();
        int n = in.nextInt();
        a = new int[h][w];
        while (n-- > 0) {
          int y = in.nextInt();
          int x = in.nextInt();
          a[x][y] = 1;
        }
        cnt = 0;
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            if (a[i][j] != 0)
              dfs(h, w, i, j, true);
          }
        }
        out.println(cnt);
      }
    }

    private void dfs(int h, int w, int x, int y, boolean first) {
      if (first) {
        cnt++;
      }
      a[x][y] = 0;
      for (int i = 0; i < 4; i++) {
        int nx = x + vx[i];
        int ny = y + vy[i];
        if (isok(h, w, nx, ny)) {
          dfs(h, w, nx, ny, false);
        }
      }
    }

    private boolean isok(int h, int w, int x, int y) {
      return (x >= 0 && x < h && y >= 0 && y < w && a[x][y] != 0);
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