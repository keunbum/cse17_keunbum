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
    int tt = in.nextInt();
    solver.solve(tt, in, out);
    out.close();
  }
  static class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int[] a = new int[]{500, 300, 200, 50, 30, 10};
      int[] b = new int[]{512, 256, 128, 64, 32};
      while (testNumber-- > 0) {
        int x = in.nextInt();
        int y = in.nextInt();
        if (x == 0) {
          x = 100;
        }
        if (y == 0) {
          y = 64;
        }
        int ans = 0;
        for (int i = 0; i < 6; i++) {
          x -= i + 1;
          if (x <= 0) {
            ans += a[i];
            break;
          }
        }
        for (int i = 0; i < 5; i++) {
          y -= (1 << i);
          if (y <= 0) {
            ans += b[i];
            break;
          }
        }
        out.println(ans * (int) 1e4);
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