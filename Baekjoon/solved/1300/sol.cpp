#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int low = 1, high = (int) 1e9;
  for (int it = 0; it < 100; it++) {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += min(mid / i, n);
    }
    if (cnt >= k) high = mid;
    else low = mid + 1;
  }
  cout << ((low + high) >> 1) << '\n';
  return 0;
}                                     