import java.io.*;
import java.util.*;

public class Main {
  InputReader in;
  PrintWriter out;
  int[] r;
  int f(int x) {
    return x == r[x] ? x : (r[x] = f(r[x]));
  }
  void solve() {
    int n = in.nextInt();
    r = new int[n + 1];
    for (int i = 1; i <= n; i++) {
      r[i] = i;
    }
    int m = in.nextInt();
    while (m-- > 0) {
      int x = in.nextInt();
      int y = in.nextInt();
      if (f(x) != f(y)) {
        r[f(y)] = f(x);
      }
    }
    int ans = 0;
    int foo = f(1);
    for (int i = 2; i <= n; i++) {
      if (foo == f(i)) ans++;
    }
    out.println(ans);
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