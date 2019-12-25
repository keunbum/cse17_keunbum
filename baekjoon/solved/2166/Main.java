import java.io.*;
import java.util.*;
import java.math.*;

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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int[] x = new int[n + 1];
      int[] y = new int[n + 1];
      for (int i = 0; i < n; i++) {
        x[i] = in.nextInt();
        y[i] = in.nextInt();
      }
      x[n] = x[0];
      y[n] = y[0];
      long ans = 0;
      for (int i = 0; i < n; i++) {
        ans += 1L * x[i] * y[i + 1] - 1L * y[i] * x[i + 1];
      }
      out.println(String.format("%.1f", Math.abs(ans) * 0.5));
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
