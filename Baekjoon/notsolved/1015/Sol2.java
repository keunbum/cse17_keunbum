import java.io.*;
import java.util.*;
import java.math.*;

public class Sol2 {
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
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int x = 0;
      int[] ans = new int[n];
      for (int i = 0; i < n; i++) {
        int j = max_index(a, n);
        a[j] = 1234;
        ans[j] = x++;
      }
      for (int t : ans) {
        out.print(t + " ");
      }
      out.println();
    }
    static int max_index(int[] a, int n) {
      int j = 0;
      for (int i = 1; i < n; i++) {
        if (a[i] < a[j]) {
          j = i;
        }
      }
      return j;
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