#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> a;

void foo(int x, int y, int n) {
  int s = n / 3;
  if (n == 1) {
    a[x][y] = '*';
    return;
  }
  for (int i = x; i < x + n; i += s) {
    for (int j = y; j < y + n; j += s) {
      if (i == x + s && j == y + s) continue;
      foo(i, j, s);
    }
  } 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n, string(n, ' '));
  foo(0, 0, n);
  if (n == 1) a[0][0] = ' ';
  for (int i = 0; i < n; i++) {
    cout << a[i] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}