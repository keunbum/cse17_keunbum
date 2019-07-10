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
      int n = in.nextInt();
      int m = in.nextInt();
      List<Integer>[] g = new ArrayList[n];
      for (int i = 0; i < n; i++) {
        g[i] = new ArrayList<>();
      }
      int[] deg = new int[n];
      while (m-- > 0) {
        int x = in.nextInt();
        int y = in.nextInt();
        x--; y--;
        g[x].add(y);
        deg[y]++;
      }
      Queue<Integer> s = new LinkedList<>();
      for (int i = 0; i < n; i++) {
        if (deg[i] == 0) s.offer(i);
      }
      while (!s.isEmpty()) {
        int i = s.poll();
        out.print((i + 1) + " ");
        for (int to : g[i]) {
          if (--deg[to] == 0) {
            s.offer(to);
          }
        }
      }
      out.println();
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