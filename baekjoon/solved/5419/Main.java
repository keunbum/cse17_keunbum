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
    static int[] fenw;
    static int n;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      while (testNumber-- > 0) {
        n = in.nextInt();
        ArrayList<Event> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
          int x = in.nextInt();
          int y = in.nextInt();
          a.add(new Event(x, y, y));
        }
        Collections.sort(a, new Comparator<Event>() {
          public int compare(Event a, Event b) {
            return a.y - b.y;
          }
        });
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          a.get(i).y = (i > 0 && a.get(i).ty == a.get(i - 1).ty) ? a.get(i - 1).y : ++cnt;
        }
        Collections.sort(a, new Comparator<Event>() {
          public int compare(Event a, Event b) {
            int z = b.x - a.x;
            if (z == 0) {
              z = a.y - b.y;
            }
            return z;
          }
        });
        fenw = new int[n + 1];
        long ans = 0;
        for (int i = 0; i < n; i++) {
          int foo = a.get(i).y;
          ans += Get(foo);
          Modify(foo, 1);
        }
        out.println(ans);
      }
    }
    
    public void Modify(int x, int v) {
      while (x <= n) {
        fenw[x] += v;
        x += x & (-x);
      }
    }
    
    public int Get(int x) {
      int res = 0;
      while (x > 0) {
        res += fenw[x];
        x -= x & (-x);
      }
      return res;
    }
    
    static class Event {
      int x;
      int y;
      int ty;
      
      public Event(int x, int y, int ty) {
        this.x = x;
        this.y = y;
        this.ty = ty;
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
