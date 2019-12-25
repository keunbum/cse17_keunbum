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
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }
  static class TaskA {
    static int[] rot = new int[12345];
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[][] a = new int[n][n];
      while (k-- > 0) {
        int x = in.nextInt();
        int y = in.nextInt();
        x--; y--;
        a[x][y] = -1; // apple
      }
      int l = in.nextInt();
      while (l-- > 0) {
        int t = in.nextInt();
        char c = in.next().charAt(0);
        rot[t] = (c == 'L' ? 1 : 3);
      }
      int dir = 1;
      int x = 0;
      int y = 0;
      int ans = 1;
      a[x][y] = ans;
      int tx = 0, ty = 0;
      while (true) {
        ++ans;
        x += "2101".charAt(dir) - '1';
        y += "1210".charAt(dir) - '1';
        if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] >= 1) {
          break;
        }
        int pre = a[x][y];
        a[x][y] = ans;
        if (pre == 0) { // not apple
          for (int i = 0; i < 4; i++) {
            int u = tx + "2101".charAt(i) - '1';
            int v = ty + "1210".charAt(i) - '1';
            if (u < 0 || u >= n || v < 0 || v >= n) continue;
            if (a[u][v] == a[tx][ty] + 1) {
              a[tx][ty] = 0;
              tx = u;
              ty = v;
              break;
            }
          }
        }
        dir = (dir + rot[ans - 1]) & 3;
      }
      out.println(ans - 1);
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