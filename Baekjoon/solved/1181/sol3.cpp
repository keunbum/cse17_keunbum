#include <iostream>
#include <algorithm>

using namespace std;

string a[23456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, [&](const string &x, const string &y) {
    if (x.size() != y.size()) return x.size() < y.size();
    return x < y;
  });
  int e = (int) (unique(a, a + n) - a);
  for (int i = 0; i < e; i++) {
    cout << a[i] << '\n';
  }
  return 0;
}