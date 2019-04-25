#include <iostream>

using namespace std;

int a[123][123]; // game board
int v[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // Down, Right, Up, Left
int rd[10001]; // rotation direction per second

inline bool ishit(int n, int x, int y) {
  return (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 2);
}

void print(int time, int n, int dir) {
  cout << "[after " << time << "] dir  = " << dir << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
       cout << a[i][j];
    }
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, l;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    a[--x][--y] = 1; // apple
  }
  cin >> l;
  for (int i = 0; i < l; i++) {
    int t;
    char c;
    cin >> t >> c;
    rd[t] = (c == 'L' ? 1 : -1); // rotation
  }
  int time = 1;
  int x = 0, y = 0; // head
  int qx[123456], qy[123456], f = 0, r = 0;
  qx[r] = x, qy[r++] = y;
  int dir = 1; // direction number in array v
  a[x][y] = 2; // after -1 second
  while (1) {
    x += v[dir][0];
    y += v[dir][1];
    if (ishit(n, x, y)) break;
    if (!a[x][y]) { // not apple
      a[qx[f]][qy[f]] = 0;
      f++;
    }
    a[x][y] = 2;
    qx[r] = x, qy[r++] = y;
    dir = (dir + rd[time] + 4) % 4;
    //print(time, n, dir);
    time++;
  }
  cout << time << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
