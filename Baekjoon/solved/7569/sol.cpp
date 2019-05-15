#include <iostream>
#include <queue>

using namespace std;

const int N = 123;

struct Point {
  int x, y, z;
  Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

int a[N][N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, h;
  cin >> m >> n >> h;
  int all = 0, ripe = 0;
  queue<Point> que[2];
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) a[i][j][k] = -1;
  for (int k = 1; k <= h; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int t;
        cin >> t;
        a[i][j][k] = t;
        if (t != -1) all++;
        if (t == 1) {
          ripe++;
          que[0].emplace(i, j, k);
        }
      }
    }
  }
  //cerr << "tomato = " << all << '\n';
  if (all == ripe) { cout << 0 << '\n'; return 0; }
  int ans = 0;
  int tog = 0;
  //cerr << "ans = " << ans << '\n';  
  //cerr << "ripe = " << ripe << '\n';
  while (!que[tog].empty()) {
    Point c = que[tog].front();                        
    que[tog].pop();                                    
    for (int i = 0; i < 6; i++) {                      
      int x = c.x + "111102"[i] - '1';                 
      int y = c.y + "110211"[i] - '1';                 
      int z = c.z + "201111"[i] - '1';                 
      if (a[x][y][z] != 0) continue;                   
      a[x][y][z] = 1;                                  
      ripe++;                                          
      que[!tog].emplace(x, y, z);                       
    }
    if (que[tog].empty()) {
      ans++;
      tog ^= 1;
      //cerr << "ans = " << ans << '\n';  
      //cerr << "ripe = " << ripe << '\n';
      if (all == ripe) { cout << ans <<'\n'; return 0;}
    }
  }                                                    
  cout << -1 << '\n';      
  return 0;
}
