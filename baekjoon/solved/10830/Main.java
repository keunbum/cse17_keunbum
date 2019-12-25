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
    static final int md = (int) 1e3;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      long b = in.nextLong();
      Matrix a = new Matrix(n);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a.a[i][j] = in.nextInt();
        }
      }
      Matrix ans = new Matrix(n);
      while (b > 0) {
        if (b % 2 == 1) { ans = ans.multiply(a); }
        a = a.multiply(a);
        b >>= 1;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          out.print(ans.a[i][j] + " ");
        }
        out.println();
      }
    }
    static class Matrix {
      int n;
      int[][] a;
      public Matrix() {
        this(0);
      }
      public Matrix(int n) {
        this.n = n;
        a = new int[n][n];
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            a[i][j] = 0;
          }
          a[i][i] = 1;
        }
      }
      public Matrix multiply(Matrix other) {
        Matrix ret = new Matrix(n);
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
              sum += this.a[i][k] * other.a[k][j];
            }
            ret.a[i][j] = sum % md;
          }
        }
        return ret;
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

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}