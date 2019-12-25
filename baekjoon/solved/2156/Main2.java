import java.io.*;
import java.util.*;

public class Main2 {
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    int n = in.nextInt();
    int[] a = new int[n + 2];
    for (int i = 1; i <= n; i++) {
      a[i] = in.nextInt();
    }
    int[][] f = new int[2][n + 2];
    f[0][1] = a[1];
    f[0][2] = a[2];
    f[1][2] = a[1] + a[2];
    for (int i = 3; i <= n + 1; i++) {
      f[0][i] = max3(f[0][i - 2], f[1][i - 2], f[1][i - 3]) + a[i];
      f[1][i] = f[0][i - 1] + a[i];
    }
    out.println(max3(f[0][n + 1], f[1][n + 1], f[1][n])); 
    out.close();
  }
  public static int max3(int a, int b, int c) {
    return Math.max(Math.max(a, b), c);
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