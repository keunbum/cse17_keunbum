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
    static final int N = 10001;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int[][] a = new int[3][N];
      int n = in.nextInt();
      for (int i = 1; i <= n; i++) {
       a[0][i] = in.nextInt();
       a[1][i] = a[0][i];
       a[2][i] = a[0][i];
      }
      a[0][2] += a[1][1];
      for (int i = 3; i <= n; i++) {
        a[0][i] += Math.max(a[1][i - 1], a[2][i - 1]);
        a[1][i] += max3(a[0][i - 2], a[1][i - 2], a[2][i - 2]);
        a[2][i] += max3(a[0][i - 3], a[1][i - 3], a[2][i - 3]);
      }
      out.println(Math.max(max3(a[0][n], a[1][n], a[2][n]), max3(a[0][n-1], a[1][n-1], a[2][n-1])));
    }
    public int max3(int a, int b, int c) {
      return Math.max(a, Math.max(b, c));
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