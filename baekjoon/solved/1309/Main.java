import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    int n = in.nextInt();
    Matrix ans = new Matrix(new int[][] {{7, 3}, {3, 1}});
    Matrix e = new Matrix(new int[][] {{2, 1}, {1, 0}});
    while (n > 0) {
      if ((n & 1) == 1) {
        ans = ans.multiply(e);
      }
      e = e.multiply(e);
      n >>= 1;
    }
    out.println(ans.a[1][1]);
    out.close();
  }
  static class Matrix {
    public int[][] a;
    Matrix(int[][] a) {
      this.a = a;
    }
    public Matrix multiply(Matrix other) {
      Matrix res = new Matrix(new int[][] {{0, 0}, {0, 0}});
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          int sum = 0;
          for (int k = 0; k < 2; k++) {
            sum += this.a[i][k] * other.a[k][j];
          }
          res.a[i][j] = sum % 9901; 
        }
      }
      return res;
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