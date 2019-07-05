#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int) 1e6;

int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  make_heap(a, a + n);
  sort_heap(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a, b;
      cin >> a >> b;
      int c = a & b;
      int d = a | b;
      int g = c % d;
      cout << c << ' ' << d << ' ' << g << '\n';
    }
  }
  return 0;
}