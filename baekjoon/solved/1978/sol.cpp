#include <iostream>

using namespace std;

bool com[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  com[1] = true;
  for (int i = 2; i < 1001; i++) {
    if (com[i]) continue;
    for (int j = i + i; j < 1001; j += i) {
      com[j] = true;
    }
  }
  int t;
  cin >> t;
  int ans = t;
  while (t--) {
    int n;
    cin >> n;
    ans -= com[n];
  }
  cout << ans << '\n';
  return 0;
}