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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[][] a = new int[n + 1][3];
      for (int i = 0; i < n; i++) {
        int t = in.nextInt();
        a[t][0] = in.nextInt();
        a[t][1] = in.nextInt();
        a[t][2] = in.nextInt();
      }
      int cnt = 1;
      for (int i = 1; i <= n; i++) {
        if (cmp(a, i, k)) cnt++;
      }
      out.println(cnt);
    }

    boolean cmp(int[][] a, int x, int y) {
      for (int i = 0; i < 3; i++) {
        if (a[x][i] == a[y][i]) continue;
        return a[x][i] > a[y][i];
      }
      return false;
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