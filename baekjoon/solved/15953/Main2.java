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
    int tt = in.nextInt();
    solver.solve(tt, in, out);
    out.close();
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      while (testNumber-- > 0) {
        int a = in.nextInt();
        int b = in.nextInt();
        if (a == 0) { 
          a = 100;
        }
        if (b == 0) {
          b = 64;
        }
        int ans = a <= 1 ? 500 : a <= 3 ? 300 : a <= 6 ? 200 : a <= 10 ? 50 : a <= 15 ? 30 : a <= 21 ? 10 : 0;
        ans += b <= 1 ? 512 : b <= 3 ? 256 : b <= 7 ? 128 : b <= 15 ? 64 : b <= 31 ? 32 : 0;
        out.println(ans * 10000);
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