#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;

int a[N];
int b[N];
int A[N + 1];
int B[N + 1];
int ans[N];
int an = 0;

void Dfs(int st, int en) {
  cerr << st << ' ' << en << '\n';
  if (st == en) {
    return;
  }
  ans[an++] = b[en - 1];
  if (st + 1 == en) {
    return;
  }
  int i = A[b[en - 1]] - 1;
  int v = a[i];
  while (A[v] < A[b[en - 1]]) {
    v = b[B[v] + 1];
  }
  Dfs(0, B[v]);
  Dfs(B[v], en - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    A[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    B[b[i]] = i;
  }
  Dfs(0, n);
  for (int i = 0; i < an; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
