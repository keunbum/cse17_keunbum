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
    static int map[][];
    static int[] vx = new int[]{0, 0, -1, 1}, vy = new int[]{1, -1, 0, 0};
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      int x = in.nextInt();
      int y = in.nextInt();
      int k = in.nextInt();
      map = new int[20][20];
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          map[i][j] = in.nextInt();
      TaskA.Dice dice = new TaskA.Dice();
      int d;
      int nx, ny;
      for ( ; k > 0; k--) {
        d = in.nextInt();
        d--;  
        nx = x + vx[d];
        ny = y + vy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        x = nx;
        y = ny;
        dice.roll(d);
        if (map[x][y] != 0) {
          dice.side[5] = map[x][y];
          map[x][y] = 0;
        } else {
          map[x][y] = dice.side[5]; 
        }
        out.println(dice.side[0]);
      }
    }
    static class Dice {
      int[] side = new int[]{0, 0, 0, 0, 0, 0};
      int[] t = new int[6];
      int[][] f = new int [][]{
        {3, 1, 0, 5, 4, 2},
        {2, 1, 5, 0, 4, 3},
        {4, 0, 2, 3, 5, 1},
        {1, 5, 2, 3, 0, 4}
      };
      public void roll(int d) {
        for (int i = 0; i < 6; i++)
          t[i] = side[f[d][i]];
        for (int i = 0; i < 6; i++)
          side[i] = t[i];  
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