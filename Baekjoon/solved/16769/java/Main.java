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
      int[][] a = new int[3][2];
      for (int i = 0; i < 3; i++) {
        a[i][0] = in.nextInt();
        a[i][1] = in.nextInt();
      }
      for (int i = 0; i < 33; i++) {
        pour(a, 0, 1);
        pour(a, 1, 2);
        pour(a, 2, 0);
      }
      pour(a, 0, 1);
      for (int i = 0; i < 3; i++) {
        out.println(a[i][1]);
      }
    }

    private void pour(int[][] a, int x, int y) {
      int sum = a[x][1] + a[y][1];
      a[y][1] = Math.min(a[y][0], sum);
      a[x][1] = sum - a[y][1];
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