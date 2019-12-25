#include <iostream>

using namespace std;

const int N = 2000;

int md;
int a[N + 1][N + 1];

inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}

inline int mul(int a, int b) {
  return a * b % md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m >> md;
  int ans = 1;
  for (int i = 0; i <= N; i++) {
    a[i][0] = 1;
    a[i][i] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) {
      a[i][j] = add(a[i - 1][j], a[i - 1][j - 1]);
    }
  }
  while (n && m) {
    ans = mul(ans, a[n % md][m % md]);
    n /= md;
    m /= md;
  }
  cout << ans << '\n';
  return 0;
}