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
      int w = in.nextInt();
      int h = in.nextInt();
      int k = in.nextInt();
      if (w * h < k) {
        out.println(0);
      } else {
        int x, y, i, tx = 0, ty = 1;
        int g = h - 1, t, cnt = 0;
        for (x = y = i = 1; i < k; i++) {
          x += tx;
          y += ty;
          if (i == g) {
            g = i + (tx != 0 ? h : w) - 1 - cnt / 2;
            t = tx;
            tx = ty;
            ty = -t;
            cnt++;
          }
        }
        out.println(x + " " + y);
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