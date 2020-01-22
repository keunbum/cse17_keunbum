#include <iostream>
#include <set>

using namespace std;

int n, k;
int a[10], v[10];
bool chk[10];
set<int> s;

void Dfs(int d) {
  if (d == k) {
    int key = 0;
    for (int i = 0; i < k; i++) {
      key = key * (v[i] / 10 > 0 ? 100 : 10) + v[i];
    }
    s.insert(key);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!chk[i]) {
      chk[i] = true;
      v[d] = a[i];
      Dfs(d + 1);
      chk[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Dfs(0);
  cout << s.size() << '\n';
  return 0;
}
