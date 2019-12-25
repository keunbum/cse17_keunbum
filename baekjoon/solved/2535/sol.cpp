#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int cnt[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> get<1>(a[i]) >> get<2>(a[i]) >> get<0>(a[i]);
  }
  sort(a.rbegin(), a.rend());
  int c = 1;
  for (int i = 0; i < n && c < 4; i++) {
    if (cnt[get<1>(a[i])] < 2) {
      cout << get<1>(a[i]) << ' ' << get<2>(a[i]) << '\n';
      cnt[get<1>(a[i])]++;
      c++;
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
