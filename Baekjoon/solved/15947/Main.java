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
    solver.solve(1, in, out);
    out.close();
  }
  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      String[] a = new String[]{"baby", "sukhwan", "very", "cute", "in", "bed", "baby", "sukhwan"}; 
      int n = in.nextInt() - 1;
      int t = n % 14;
      n /= 14;
      if ((t & 3) < 2) {
        out.println(a[t >> 2 << 1 | t & 1]);
      } else {
        out.print("tu");
        n += 4 - (t & 3);
        if (n >= 5) {
          out.println("+ru*" + n);
        } else {
          while (n-- > 0) {
            out.print("ru");
          }
          out.println();
        }
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