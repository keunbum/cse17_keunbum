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
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int g = 0;
      for (int i = 1; i < n; i++) {
        g = gcd(g, Math.abs(a[i] - a[i - 1]));
      }
      List<Integer> ans = new ArrayList<>();
      for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) {
          ans.add(i);
          if (i != g / i) ans.add(g / i);
        }
      }
      ans.add(g);
      Collections.sort(ans);
      for (int x : ans) {
        out.print(x + " ");
      }
      out.println();
    }
    int gcd(int a, int b) {
      while (b > 0) {
        int t = a % b;
        a = b;
        b = t;
      }
      return a;
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