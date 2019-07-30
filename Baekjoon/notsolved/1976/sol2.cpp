#include <iostream>

using namespace std;

const int N = 234;

int adj[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> adj[i][j];
    }
    adj[i][i] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (adj[i][k] == 0) continue;
      for (int j = 1; j <= n; j++) {
        adj[i][j] |= adj[i][k] & adj[k][j];
      }
    }
  }
  int f;
  cin >> f;
  while (--m) {
    int t;
    cin >> t;
    if (adj[f][t] == 0) { cout << "NO" << '\n'; return 0; }
  }
  cout << "YES" << '\n';
  return 0;
}