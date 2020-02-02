#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> f(n + 1);
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  } 
  int m;
  cin >> m;
  vector<int> b(m + 2);
  b[0] = 0;
  b[m + 1] = n + 1;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int ans = 1;
  for (int i = 1; i <= m + 1; i++) {
    ans *= f[b[i] - b[i - 1] - 1];
  }
  cout << ans << '\n';
  return 0;
}
