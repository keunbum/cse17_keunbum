#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Point {
  int x, y;

  Point() {x = y = 0;}

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  
  Point operator+ (const Point &b) const {
    return Point(this->x + b.x, this->y + b.y);
  }
};

const int N = 50;

int cnt;
int a[N][N];
Point v[] = {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};

inline bool isok(int h, int w, Point p) {
  int x = p.x, y = p.y;
  return x >= 0 && x < h && y >= 0 && y < w && a[x][y] != 0;
}

void bfs(int h, int w, int x, int y) {
  if (!isok(h, w, Point(x, y)))
    return;
  cnt++;
  queue<Point> que;
  que.push(Point(x, y));
  a[x][y] = 0;
  while (!que.empty()) {
    Point cur = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      Point n = Point(cur + v[i]);
      if (isok(h, w, n)) {
        a[n.x][n.y] = 0;
        que.push(n);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int w, h, n, x, y;
    cin >> w >> h >> n;
    cnt = 0;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      cin >> y >> x;
      a[x][y] = 1;
    }
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        bfs(h, w, i, j);
    cout << cnt << '\n';
  } 
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
