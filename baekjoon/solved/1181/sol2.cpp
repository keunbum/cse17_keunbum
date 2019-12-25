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
  for (int i = 0; i < n; i++) {
    if (i && a[i] == a[i - 1]) continue;
    cout << a[i] << '\n';
  }
  return 0;
}