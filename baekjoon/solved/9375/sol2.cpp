#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
      string s;
      cin >> s >> s;
      if (m.find(s) != m.end()) m[s]++;
      else m[s] = 1;
    }
    int ans = 1;
    for (auto it : m) {
      ans *= it.second + 1;
    }
    ans--;
    cout << ans << '\n';
  }
  return 0;
}