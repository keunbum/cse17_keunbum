#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 0) { cout << 0 << '\n'; continue; }
    vector<string> v;
    while (n--) {
      string a, b;
      cin >> a >> b;
      v.push_back(b);
    }
    sort(v.begin(), v.end());
    vector<int> u;
    string cur = v[0];
    int cnt = 0;
    for (string x : v) {
      if (x == cur) cnt++;
      else {
        u.push_back(cnt);
        cur = x;
        cnt = 1;
      }
    }
    u.push_back(cnt);
    int ans = 1;
    for (int x : u) {
      ans *= (x + 1);
    }
    ans--;
    cout << ans << '\n';
  }
  return 0;
}