#include <iostream>
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

const int MAX = 1000;

int a[MAX][MAX];

inline bool isin(int x, int y, int n, int m) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  Point v[] = {Point(1,0), Point(0,1), Point(-1, 0), Point(0, -1)}; 
  cin >> m >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  queue<Point> que[2];
  int count0 = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 1)
        que[0].push(Point(i, j));
      else if (a[i][j] == 0)
        count0++;
  int day = -1;
  int tog = 0;
  while (!que[tog].empty()) {
    Point tmp = que[tog].front();
    que[tog].pop();
    for (int i = 0; i < 4; i++) {
      Point nn(tmp + v[i]);
      if (isin(nn.x, nn.y, n, m) && a[nn.x][nn.y] == 0) {
        a[nn.x][nn.y] = 1;
        count0--;
        que[tog ^ 1].push(nn);
      }
    }
    if (que[tog].empty()) {
      tog ^= 1;
      day++;
    }
  }
  if (count0 > 0) day = -1;
  cout << day << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
