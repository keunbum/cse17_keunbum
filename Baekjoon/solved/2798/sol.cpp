#include <iostream>
#include <algorithm>

using namespace std;

int a[123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = a[i] + a[j] + a[k];
        if (ans < sum && sum <= m) {
          ans = sum;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}