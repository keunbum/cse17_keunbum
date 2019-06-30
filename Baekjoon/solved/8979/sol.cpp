#include <iostream>
#include <algorithm>

using namespace std;

int a[1234][3];

bool comp(int x, int y) {
  for (int i = 0; i < 3; i++) {
    if (a[x][i] == a[y][i]) continue;
    return a[x][i] > a[y][i];
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    cin >> a[t][0] >> a[t][1] >> a[t][2];
  }
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (comp(i, k)) cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
