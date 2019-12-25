#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;

int p[N + 1], a[N + 1], q[N + N + 5];

void P(int v) {
  if (p[v] != -1) {
    P(p[v]);
    cout << ' ';
  }
  cout << v;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(p, -1, sizeof(p));
  int st, en;
  cin >> st >> en;
  int b = 0, e = 0;
  q[e++] = st;
  a[st] = 1;
  while (true) {
    int v = q[b];
    if (v == en) {
      break;
    }
    for (int i = -1; i <= 1; i++) {
      int u = v + i + (!i) * v;
      if (u >= 0 && u <= N && a[u] == 0) {
        a[u] = a[v] + 1;
        q[e++] = u;
        p[u] = v;
      }
    }
    b++;
  }
  cout << a[en] - 1 << '\n';
  P(en);
  cout << '\n';
  return 0;
}
