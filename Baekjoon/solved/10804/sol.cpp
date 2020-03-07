#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[21];
  iota(a, a + 21, 0);
  for (int i = 0; i < 10; i++) {
    int s, e;
    cin >> s >> e;
    while (s < e) swap(a[s++], a[e--]);
  }
  for (int i = 1; i <= 20; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}
