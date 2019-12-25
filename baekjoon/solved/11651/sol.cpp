#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> a[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i].second << ' ' << a[i].first << '\n';
  }
  return 0;
}