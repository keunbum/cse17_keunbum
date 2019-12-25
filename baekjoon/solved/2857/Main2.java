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
      boolean found = false;
      for (int qq = 1; qq <= 5; qq++) {
        String s = in.next();
        int n = (int) s.length();
        for (int i = 0; i < n - 2; i++) {
          int j;
          for (j = 0; j < 3; j++) {
            if (s.charAt(i + j) != "FBI".charAt(j)) {
              break;
            }
          }
          if (j == 3) {
            out.print(qq + " ");
            found = true;
            break;
          }
        }
      }
      if (!found) out.println("HE GOT AWAY!");
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