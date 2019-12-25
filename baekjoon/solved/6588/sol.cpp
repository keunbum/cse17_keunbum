#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

bool is_c[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i <= N; i++) {
    if (is_c[i]) {
      continue;
    }
    for (int j = i + i; j <= N; j += i) {
      is_c[j] = true;
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 3; i <= n / 2; i += 2) {
      int j = n - i;
      if (!is_c[i] && !is_c[j]) {
        cout << n << " = " << i << " + " << j << '\n';
        break;
      }
    }
  }
  return 0;
}
