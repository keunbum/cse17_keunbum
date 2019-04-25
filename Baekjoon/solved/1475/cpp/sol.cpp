#include <iostream>

using namespace std;

int cnt[128];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ans = 0;
  char c;
  while (cin >> c) {
    cnt[c]++;
  }
  cnt['6'] = (cnt['6'] + cnt['9'] + 1) / 2;
  for (int i = '0'; i < '9'; i++)
    ans = max(ans, cnt[i]);
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
