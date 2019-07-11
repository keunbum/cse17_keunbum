#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[9], v[9];
bool chk[9];

void dfs(int x) {
  if (x == m) {
    for (int i = 0; i < m; i++) {
      if (i) cout << ' ';
      cout << v[i];
    }
    cout << '\n';
    return;
  }  
  for (int i = 0; i < n; i++) {
    if (chk[i]) continue;
    chk[i] = true;
    v[x] = a[i];
    dfs(x + 1);
    chk[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  dfs(0);
  return 0;
}