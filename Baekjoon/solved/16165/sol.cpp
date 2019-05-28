#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> idol;
map<string, vector<string>> group;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  while (N--) {
    string team;
    cin >> team;
    int n;
    cin >> n;
    vector<string> m;
    while (n--) {
      string who;
      cin >> who;
      idol[who] = team;
      m.push_back(who);
    }
    sort(m.begin(), m.end());
    group[team] = m;
  }
  while (M--) {
    string foo;
    cin >> foo;
    int x;
    cin >> x;
    if (x) {
      cout << idol[foo] << '\n';
    } else {
      for (auto &s : group[foo]) {
        cout << s << '\n';
      }
    }
  }
  return 0;
}