#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  set<string> ans;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    ans.insert(s.substr(i, n - i));
  }
  for (auto i = ans.begin(); i != ans.end(); i++) {
    cout << *i << '\n';
  }
  return 0;
}