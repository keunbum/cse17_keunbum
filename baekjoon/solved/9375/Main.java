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
    int tt = in.nextInt();
    solver.solve(tt, in, out);
    out.close();
  }
  static class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      while (testNumber-- > 0) {
        int n = in.nextInt();
        if (n == 0) { out.println(0); continue; }
        List<String> a = new ArrayList<>();
        while (n-- > 0) {
          in.next();
          String s = in.next();
          a.add(s);
        }
        Collections.sort(a);
        int cnt = 0;
        String cur = a.get(0);
        List<Integer> b = new ArrayList<>();
        for (String x : a) {
          if (cur.compareTo(x) == 0) {
            cnt++;
          } else {
            b.add(cnt);
            cur = x;
            cnt = 1;
          }
        }
        b.add(cnt);
        int ans = 1;
        for (int x : b) {
          ans *= x + 1;
        }
        ans--;
        out.println(ans); 
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