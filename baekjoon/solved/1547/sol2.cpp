#include <iostream>

using namespace std;

int v[4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  v[1] = 1;
  while (n--) {
    int a, b;
    cin >> a >> b;
    swap(v[a], v[b]);
  }
  for (int i = 1; i <= 3; i++) {
    if (v[i]) { cout << i << '\n'; return 0; }
  }
  return 0;
}