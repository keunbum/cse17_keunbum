#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> a;
  vector<char> type;
  type.push_back('+');
  int v = 0;
  for (char c : s) {
    if (c == '+' || c == '-') {
      a.push_back(v);
      v = 0;
      type.push_back(c);
    } else {
      v = v * 10 + c - '0';
    }
  }
  a.push_back(v);
  int k;
  int n = (int) a.size();
  for (k = 0; k < n; k++) {
    if (type[k] == '-') break;
  }
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += a[i];
  }
  for (int i = k; i < n; i++) {
    ans -= a[i];
  }
  cout << ans << '\n';
  return 0;
}