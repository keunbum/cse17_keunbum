import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

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
      int[] a = new int[n];
      int[] b = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = in.nextInt();
      for (int i = 0; i < n; i++)
        b[i] = in.nextInt();
      Arrays.sort(a);
      Arrays.sort(b);
      reverse(b);
      int ans = 0;
      for (int i = 0; i < n; i++)
        ans += a[i] * b[i];
      out.println(ans);
    }
    private void reverse(int[] x) {
      int i, j;
      int n = x.length;
      for (i = 0, j = n - 1; i < j; i++, j--) {
        int t = x[i];
        x[i] = x[j];
        x[j] = t;
      }
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