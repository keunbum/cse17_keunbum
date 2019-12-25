import java.io.*;
import java.util.*;

public class Main {
  InputReader in;
  PrintWriter out;
  void solve() {
    int n = in.nextInt();
    int s = in.nextInt();
    int[] a = new int[n];
    int sum = 0;
    int ans = n + 1;
    int b = 0, e = 0;
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
      sum += a[i]; e = i;
      if (sum < s) {
        continue;
      }
      while (b <= e && sum >= s) {
        sum -= a[b++];
      }
      ans = Math.min(ans, e - b + 2);
    }
    out.println(ans > n ? 0 : ans);
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