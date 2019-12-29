#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;

int a[N];
int b[N];
int A[N + 1];
int B[N + 1];
int ans[N];
int an = 0;

inline int ToR(int i) { return i < 0 ? -1 : B[a[i]]; }
inline int ToB(int i) { return i < 0 ? -1 : A[b[i]]; }

void Dfs(int bb, int be, int rb, int re) {
  if (rb >= re) {
    return;
  }
  ans[an++] = b[re - 1];
  int pb = ToB(re - 1);
  if (pb + 1 == be) {
    Dfs(bb, pb, rb, re - 1);
    return;
  }
  int pp = pb++;
  while (pb >= 0 && pb > ToB(re - 1)) {
    pp = pb;
    pb = ToB(ToR(pb) - 1);
  }
  Dfs(bb, pp, rb, ToR(pp - 1) + 1);
  Dfs(pp, ToB(re - 1), ToR(pp - 1) + 1, re - 1);
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
  Dfs(0, n, 0, n);
  for (int i = 0; i < an; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
