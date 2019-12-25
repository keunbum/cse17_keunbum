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
      BigInteger a = BigInteger.ONE.shiftLeft(n).subtract(BigInteger.ONE);
      out.println(a);
      if (n > 20) return;
      dfs(n, 1, 3, out); 
    }
    void dfs(int n, int a, int b, PrintWriter out) {
      if (n == 1) {
        out.println(a + " " + b);
        return;
      }
      int c = 6 - a - b;
      dfs(n - 1, a, c, out);
      out.println(a + " " + b);
      dfs(n - 1, c, b, out);
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