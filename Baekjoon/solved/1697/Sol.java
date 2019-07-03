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
    static final int MAX = (int) 1e5;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[] a = new int[MAX + 1];
      a[n] = 1;
      List<Integer> que = new ArrayList<>();
      que.add(n);
      for (int i = 0; i < que.size(); i++) {
        int x = que.get(i);
        if (x == k) {
          break;
        }
        if (x - 1 >= 0 && a[x - 1] == 0) {
          a[x - 1] = a[x] + 1;
          que.add(x - 1);
        }
        if (x + 1 <= MAX && a[x + 1] == 0) {
          a[x + 1] = a[x] + 1;
          que.add(x + 1);
        }
        if (x * 2 <= MAX && a[x * 2] == 0) {
          a[x * 2] = a[x] + 1;
          que.add(x * 2);
        }
      }
      out.println(a[k] - 1);
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