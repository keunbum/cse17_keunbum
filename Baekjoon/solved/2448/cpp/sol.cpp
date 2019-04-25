#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> a;

void foo(int x, int y, int n) {
  if (n == 3) {
    a[x][y] = '*';
    a[x + 1][y - 1] = a[x + 1][y + 1] = '*';
    for (int i = 0; i < 5; i++) {
      a[x + 2][y - 2 + i] = '*';
    }
    return;
  }
  int nn = n / 2;
  foo(x, y, nn);
  foo(x + nn, y - nn, nn);
  foo(x + nn, y + nn, nn);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n, string(2 * n - 1, ' '));
  foo(0, n - 1, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}