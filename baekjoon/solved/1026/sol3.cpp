// Insertion Sort:
//   stable
#include <iostream>

using namespace std;

template <typename RandomAccessIterator>
void insertion(RandomAccessIterator first, RandomAccessIterator last) {
  for (auto it = first + 1; it < last; it++) {
    auto tmp = *it;
    auto jt = it;
    for ( ; jt > first && *(jt - 1) > tmp; jt--) {
      *jt = *(jt - 1);
    }
    *jt = tmp;
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
  insertion(a, a + n);
  insertion(b, b + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * b[n - 1 - i];
  }
  cout << ans << '\n';
  return 0;
}