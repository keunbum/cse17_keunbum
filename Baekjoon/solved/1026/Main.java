import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    int n = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int[] b = new int[n];
    for (int i = 0; i < n; i++) {
      b[i] = in.nextInt();
    }
    selectSort(a);
    selectSort(b);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] * b[n - 1 - i];
    }
    out.println(ans);
    out.close();
  }
  static void selectSort(int[] a) {
    int n = a.length;
    for (int i = n - 1; i > 0; i--) {
      int max_i = i;
      for (int j = i - 1; j >= 0; j--) {
        if (a[j] > a[max_i]) {
          max_i = j;
        }
      }
      int t = a[i];
      a[i] = a[max_i];
      a[max_i] = t;
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