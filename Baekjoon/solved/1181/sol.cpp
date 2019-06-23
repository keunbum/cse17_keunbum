#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<set<string>> a(50);
  string s;
  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    a[s.length() - 1].insert(s);
  }
  for (int i = 0; i < 50; i++) {
    for (auto it = a[i].begin(); it != a[i].end(); it++) {
      cout << (*it) << '\n';
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
