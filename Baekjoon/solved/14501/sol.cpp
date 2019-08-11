#include <iostream>

using namespace std;

const int N = 23;
const int INF = (int) 1e9;

int F[N], D[N], V[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> D[i] >> V[i];
  }
  for (int i = n + 2; i <= n + 5; i++) {
    F[i] = -INF;
  }
  for (int i = n; i >= 1; i--) {
    F[i] = max(F[i + 1], F[i + D[i]] + V[i]);
  }
  cout << F[1] << '\n';
  return 0;
}