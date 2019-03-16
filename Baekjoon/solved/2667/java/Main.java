import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.Collections;

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
    static boolean[][] dis;
    static Vector<Integer> cnt;
    static String[] a;
    int[] qx, qy;
    int[] vx, vy;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      a = new String[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.next();
      }
      qx = new int[25 * 25 * 4]; qy = new int[25 * 25 * 5];
      dis = new boolean[25][25];
      vx = new int[] {1, 0, -1, 0}; vy = new int[] {0, 1, 0, -1};
      cnt = new Vector<Integer>();
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          bfs(n, i, j, out);
      n = cnt.size();
      out.println(n);
      Collections.sort(cnt);
      for (int i = 0; i < n; i++)
        out.println(cnt.elementAt(i));
    }

    public void bfs(int n, int x, int y, PrintWriter out) {
      if (a[x].charAt(y) == '0' || dis[x][y]) {
        return;
      }
      dis[x][y] = true;
      int count = 1;
      int i = 0, e = 0;
      qx[e] = x; qy[e] = y;
      e++;
      int cx, cy;
      while (i < e) {
        cx = qx[i]; cy = qy[i];
        int nx, ny;
        for (int j = 0; j < 4; j++) {
          nx = cx + vx[j];
          ny = cy + vy[j];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx].charAt(ny) == '0' || dis[nx][ny]) {
            continue;
          }
          count++;
          dis[nx][ny] = true;
          qx[e] = nx;
          qy[e] = ny;
          e++;
        }
        i++;
      }
      cnt.addElement(count);
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