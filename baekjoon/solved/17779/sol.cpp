#include <bits/stdc++.h>

using namespace std;

inline int D(int a, int b, int c, int X, int Y) {
  return a * X + b * Y + c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 5;
  const int inf = (int) 1e9;
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n)); // population
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = inf;
  vector<vector<int>> b(n, vector<int>(n)); // map
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int da = 1; y - da >= 0; da++) {
        for (int db = 1; x + da + db < n && y + db < n; db++) {
          // draw map -> 하나의 선거구에는 적어도 하나의 구역이 포함되어야 한다.
          // It's important.. need a formula
//          cerr << "x = " << x + 1 << " y = " << y + 1 << " d1 = " << da << " d2 = " << db << '\n';
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              if (D(1, 1, -(x + y), i, j) < 0 && i < x + da && j <= y) b[i][j] = 0; else // 1
              if (D(1, -1, -(x - y), i, j) < 0 && i <= x + db && j > y) b[i][j] = 1; else // 2
              if (D(1, -1, -(x - y + 2 * da), i, j) > 0 && i >= x + da && j < y - da + db) b[i][j] = 2; else // 3
              if (D(1, 1, -(x + y + 2 * db), i, j) > 0 && i > x + db && j >= y - da + db) b[i][j] = 3; else // 4
              b[i][j] = 4; // 5
            }
          }
          // debug
          /*
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              if (j > 0) {
                cerr << ' ';
              }
              cerr << b[i][j] + 1;
            }
            cerr << '\n';
          }
          cerr << endl;*/
          // get sum
          vector<int> c(N);            
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              c[b[i][j]] += a[i][j];
            }
          }
          // update ans
          int cur = *max_element(c.begin(), c.end()) - *min_element(c.begin(), c.end());
//          cerr << cur << '\n';
          ans = min(ans, cur);        
        }
      }
    }
  }
  // 0-indexed!!!
  cout << ans << '\n';
  return 0;
}
