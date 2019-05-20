#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto dis = [&](string x, string y) {
    int cnt = 0;
    for (int i = 0; i < (int) x.size(); i++) {
      if (x[i] - y[i]) cnt++;
    }
    return cnt;
  };
  string a, b;
  cin >> a >> b;
  int ans = 50;
  int n = (int) a.size();
  int m = (int) b.size();
  for (int i = 0; i + n <= m; i++) {
    ans = min(ans, dis(a, b.substr(i, n)));
  }
  cout << ans << '\n';
  return 0;
}