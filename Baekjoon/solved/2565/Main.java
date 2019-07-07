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
    static final int N = 500;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int[] a = new int[N + 1];
      for (int i = 0; i < n; i++) {
        int x = in.nextInt();
        int y = in.nextInt();
        a[x] = y;
      }
      List<Integer> b = new ArrayList<>();
      for (int i = 1; i <= N; i++) {
        if (a[i] > 0) {
          b.add(a[i]);
        }
      }
      int m = (int) b.size();
      int max = 1;
      int[] dp = new int[N + 1];
      for (int i = 0; i < m; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
          if (b.get(j) < b.get(i)) {
            dp[i] = Math.max(dp[i], dp[j] + 1);
          }
        }
        max = Math.max(max, dp[i]);
      }
      out.println(n - max);
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