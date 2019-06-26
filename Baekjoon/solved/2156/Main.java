import java.io.*;
import java.util.*;

public class Main {
  InputReader in;
  PrintWriter out;
  void solve() {
    int n = in.nextInt();
    int[] a = new int[n + 1];
    for (int i = 1; i <= n; i++) {
      a[i] = in.nextInt();
    }
    if (n == 1) { out.println(a[1]); return; }
    int[] ans = new int[n + 1];
    ans[1] = a[1];
    ans[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
      ans[i] = Math.max(ans[i - 1], Math.max(ans[i - 2] + a[i], ans[i - 3] + a[i - 1] + a[i]));
    }
    out.println(ans[n]);
  }
  void run() {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out);
    solve();
    out.close();
  }
  class InputReader {
    BufferedReader br;
    StringTokenizer st;
    public InputReader(InputStream f) {
      br = new BufferedReader(new InputStreamReader(f), 32768);
      st = null;
    }
    String next() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return st.nextToken();
    }
    int nextInt() {
      return Integer.parseInt(next());
    }
  }
  public static void main(String[] args) {
    new Main().run();
  }
}