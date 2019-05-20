// Two horizontal lines should not be continuous or touch each other.
// Try to manipulate the result of the ladder game by adding a horizontal line to the ladder.
// At this time, the result of the i-th vertical line should be i.
// Write a program that calculates the minimum number of horizontal lines that must be added to do this.
// If the answer is greater than 3, -1 is output. Also, -1 is output even when it is impossible.

#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>

using namespace std;

bool a[32][12];
int v[11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  iota(v + 1, v + n + 1, 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    a[x][y] = true;
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j < n; j++) {
      if (a[i][j]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (v[i] != i) {
      ok = false;
      break;
    }
  }
  cout << (ok ? 0 : -1) << '\n';
  return 0;
}
