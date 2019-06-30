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
    Task solver = new Task();
    solver.solve(1, in, out);
    out.close();
  }
  static class Task {
    static int[] x, y, z;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      x = new int[n + 1];
      y = new int[n + 1];
      z = new int[n + 1];
      for (int i = 1; i <= n; i++) {
        int t = in.nextInt();
        x[t] = in.nextInt();
        y[t] = in.nextInt();
        z[t] = in.nextInt();
      }
      int ans = 1;
      for (int i = 1; i <= n; i++) {
        if (compare(i, k) > 0) ans++;
      }
      out.println(ans);
    }
    static int compare(int i, int j) {
      if (x[i] != x[j]) return x[i] - x[j];
      if (y[i] != y[j]) return y[i] - y[j];
      if (z[i] != z[j]) return z[i] - z[j];
      return 0;
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