// Selection Sort
// Not stable

#include <iostream>

using namespace std;

template <typename RandomAccessIterator>
void select(RandomAccessIterator first, RandomAccessIterator last) {
  for (auto it = first; it < last - 1; it++) {
    auto mn = it;
    for (auto jt = it + 1; jt < last; jt++) {
      if (*jt < *mn) {
        mn = jt;
      }
    }
    iter_swap(it, mn);
  }
} 

int a[56], b[56];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  select(a, a + n);
  select(b, b + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * b[n - 1 - i];
  }
  cout << ans << '\n';
  return 0;
}