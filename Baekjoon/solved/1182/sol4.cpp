#include <iostream>

using namespace std;

int n, s, ans;
int a[21];

void dfs(int pos, int sum) {
  if (sum + a[pos] == s) ans++;
  if (pos + 1 == n) return;
  dfs(pos + 1, sum);
  dfs(pos + 1, sum + a[pos]);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dfs(0, 0);
  cout << ans << '\n';
  return 0;
}