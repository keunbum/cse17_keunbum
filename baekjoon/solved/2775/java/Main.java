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
    solver.compute();
    int tt = in.nextInt();
    solver.solve(tt, in, out);
    out.close();
  }

  static class TaskA {
    int[][] m;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      while (testNumber-- > 0) {
        int k = in.nextInt();
        int n = in.nextInt();
        out.println(m[k][n]);
      }
    }
    public void compute() {
      m = new int[15][15];
      for (int i = 1; i < 15; i++) {
        m[0][i] = i;
        m[i][1] = 1;
      }
      for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
          m[i][j] = m[i][j - 1] + m[i - 1][j];
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