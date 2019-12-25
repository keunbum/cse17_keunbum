#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a = 0;
  int b = m;
  while (true) {
    int x = a;
    int y = b;
    for (int i = 1; i <= n - 2; i++) {
      x += y;
      swap(x, y);
    }
    if (y == m) {
      break;
    }
    if (y < m) {
      a++;
    } else {
      b--;
    }
  }  
  cout << a << '\n' << b << '\n';
  return 0;
}