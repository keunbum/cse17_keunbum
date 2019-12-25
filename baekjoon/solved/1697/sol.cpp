#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100001;

int a[N];
bool chk[N];
int que[N * 3];

inline int vx(int n, int i) {
  if (i == 0)
    return n - 1; else
  if (i == 1)
    return n + 1;
  else
    return n * 2;
}

void bfs(int n, int k) {
  int i, j, e = 0;
  que[e++] = n;
  chk[n] = true;
  a[n] = 0;
  for (i = 0; i < e; i++) {
    n = que[i];
    if (n == k)
      break;
    for (j = 0; j < 3; j++) {
      int nn = vx(n, j);
      if (nn >= 0 && nn < N && !chk[nn]) {
        que[e++] = nn;
        chk[nn] = true;
        a[nn] = a[n] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  bfs(n, k);
  cout << a[k] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}