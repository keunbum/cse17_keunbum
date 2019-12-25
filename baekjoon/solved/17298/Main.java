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
      int[] a = new int[n];
      int[] stk = new int[n + 1];
      int[] ans = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int top = 0;
      for (int i = n - 1; i >= 0; i--) {
        while (top > 0 && stk[top - 1] <= a[i]) top--;
        ans[i] = top > 0 ? stk[top - 1] : -1;
        stk[top++] = a[i];
      }
      for (int i = 0; i < n; i++) {
        out.print(ans[i] + " ");
      }
      out.println();
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