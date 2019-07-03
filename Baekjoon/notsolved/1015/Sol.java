import java.io.*;
import java.util.*;
import java.math.*;

public class Sol {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(1, in, out);
    out.close();
  }
  static class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      E[] a = new E[n];
      for (int i = 0; i < n; i++) {
        a[i] = new E(in.nextInt(), i);
      }
      Arrays.sort(a);
      int[] ans = new int[n];
      for (int i = 0; i < n; i++) {
        ans[a[i].index] = i;
      }
      for (int x : ans) {
        out.print(x + " ");
      }
      out.println();
    }
    static class E implements Comparable<E> {
      int v;
      int index;
      public E(int v, int index) {
        this.v = v;
        this.index = index;
      }
      public int compareTo(E o) {
        return Integer.compare(v, o.v);
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
  }
}