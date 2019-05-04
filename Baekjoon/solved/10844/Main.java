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
      int[][] a = new int[101][10];
      a[1][0] = 0;
      for (int i = 1; i < 10; i++) {
        a[1][i] = 1;
      }
      for (int i = 2; i <= n; i++){
        a[i][0] = a[i - 1][1];
        for (int j = 1; j < 9; j++)
          a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % 1000000000;
        a[i][9] = a[i - 1][8];
      }
      int ans = 0;
      for (int i = 0; i < 10; i++)
        ans = (ans + a[n][i]) % 1000000000;
      out.println(ans);
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