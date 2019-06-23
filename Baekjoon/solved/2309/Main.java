import java.io.*;
import java.util.*;

public class Main {
  InputReader in;
  PrintWriter out;
  public static void main(String[] args) {
    new Main().solve();
  }
  public void bubbleSort(int[] a) {
    int n = a.length;
    for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (a[j] > a[j + 1]) {
          int t = a[j];
          a[j] = a[j + 1];
          a[j + 1] = t;
        }
      }
    }
  }
  void solve() {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out);
    int[] a = new int[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
      a[i] = in.nextInt();
      sum += a[i];
    }
    sum -= 100;
    for (int i = 0; i < 9; i++) {
      for (int j = i + 1; j < 9; j++) {
        if (a[i] + a[j] == sum) {
          a[i] = a[j] = 100;
          bubbleSort(a);
          for (int k = 0; k < 7; k++) {
            out.println(a[k]);
          }
        }
      }
    }
    out.close();
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