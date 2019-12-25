import java.io.*;
import java.util.*;

public class Main {
  InputReader in;
  PrintWriter out;
  void solve() {
    int n = in.nextInt();
    int[] x = new int[2 * n];
    int[] y = new int[2 * n]; 
    for (int i = 0; i < n; i++) {
      int a = in.nextInt();
      int b = in.nextInt();
      x[2 * i] = a;
      x[2 * i + 1] = a + 10;
      y[2 * i] = b;
      y[2 * i + 1] = b  + 10;
    }
    Arrays.sort(x);
    Arrays.sort(y);
    for (int i = 0; i < n * 2 - 1; i++) {
      for (int j = 0; j < n * 2 - 1; j++) {
        for (int k = 0; k < n; k++) {
          
        }
      }
    }
  }
  void run() {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out);
    solve();
    out.close();
  }
  class InputReader {
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

  public static void main(String[] args) {
    new Main().run();
  }
}