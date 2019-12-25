#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<string> s;
  while (n--) {
    string foo;
    cin >> foo;
    s.insert(foo);
  }
  set<string> ans;
  while (m--) {
    string bar;
    cin >> bar;
    if (s.find(bar) != s.end()) {
      ans.insert(bar);
    }
  }
  cout << ans.size() << '\n';
  for (auto i = ans.begin(); i != ans.end(); i++) {
    cout << (*i) << '\n';
  }
  return 0;
}