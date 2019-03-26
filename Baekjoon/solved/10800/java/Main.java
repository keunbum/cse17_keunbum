import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      Ball[] a = new Ball[n];
      int[] ans = new int[n];
      int[] csum = new int[n];
      int tsum = 0;
      for (int i = 0; i < n; i++) {
        a[i] = new Ball(i, in.nextInt() - 1, in.nextInt());
      }
      Arrays.sort(a, new Comparator<Ball>() {
        @Override
        public int compare(Ball o1, Ball o2) {
          return Integer.compare(o1.size, o2.size);
        }
      });
      for (int i = 0; i < n; i++) {
        int e = i;
        while (e < n && a[e].size == a[i].size) e++;
        for (int j = i; j < e; j++) {
          ans[a[j].i] = tsum - csum[a[j].color];
        }
        for (int j = i; j < e; j++) {
          tsum += a[j].size;
          csum[a[j].color] += a[j].size;
        }
        i = e - 1;
      } 
      for (int i = 0; i < n; i++) {
        out.println(ans[i]);
      }
    }

    static class Ball {
      int i;
      int color;
      int size;

      Ball(int i, int color, int size) {
        this.i = i;
        this.color = color;
        this.size = size;
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