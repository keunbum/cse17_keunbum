import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
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
      String s = in.next();
      int v = 0;
      List<Integer> a = new ArrayList<>();
      List<Character> type = new ArrayList<>();
      type.add('+');
      for (char c : s.toCharArray()) {
        if (c == '+' || c == '-') {
          a.add(v);
          v = 0;
          type.add(c);
        } else {
          v = v * 10 + c - '0';
        }
      }
      a.add(v);
      int ans = 0;
      int n = a.size();
      int k;
      for (k = 0; k < n; k++) {
        if (type.get(k) == '-') break;
      } 
      for (int i = 0; i < k; i++) {
        ans += a.get(i);
      }
      for (int i = k; i < n; i++) {
        ans -= a.get(i);
      }
      out.println(ans);
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