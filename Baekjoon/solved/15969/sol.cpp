#include <bits/stdc++.h>

using namespace std;

int a[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << (*max_element(a, a + n) - *min_element(a, a + n)) << '\n';
  return 0;
}
