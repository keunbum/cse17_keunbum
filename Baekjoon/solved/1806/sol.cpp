#include <iostream>

using namespace std;

const int N = 123456;

int a[N];
long long ac[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  cin >> a[0];
  if (a[0] >= s) { cout << 1 << '\n'; return 0; }
  ac[1] = ac[0] + a[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    ac[i + 1] = ac[i] + a[i];
    int j = -1;
    if (ans) j = i - ans + 1;
    if (ac[i + 1] - ac[j + 1] < s) continue;
    for (j++; j < i; j++) {
      if (ac[i + 1] - ac[j + 1] < s) {
        ans = i - j + 1;
        break;
      }
    }
    if (j == i) ans = 1;
  }
  cout << ans << '\n';
  return 0;
}