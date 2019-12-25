#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
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
    v.push_back(i + 1);
    dfs(x + 1);
    chk[i] = false;
    v.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  dfs(0);
  return 0;
}