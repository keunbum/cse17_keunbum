#include <bits/stdc++.h>

using namespace std;

int a[1234];

int main() {
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      float foo;
      scanf("%f", &foo);
      a[i] = (int) (foo * 100 + 0.5);
      sum += a[i];
    }
    sort(a, a + n, [&](int p, int q) { return p > q; });
    auto d = div(sum, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += abs(a[i] - (d.quot + (int) (i < d.rem)));
    }
    printf("$%.2f\n", ans / 200.0);
  }
  return 0;
}
