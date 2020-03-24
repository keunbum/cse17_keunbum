#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int automaton[9][2] = {
    {1, 2}, // 0
    {3, 0}, // 1
    {4, 3}, // 2
    {3, 3}, // 3
    {5, 3}, // 4
    {5, 6}, // 5
    {1, 7}, // 6
    {8, 7}, // 7
    {5, 0}, // 8
  };
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int state = 0;
    for (char c : s) {
      state = automaton[state][(int) (c - '0')];
    }
//    cerr << "state = " << state << '\n';
    cout << (set<int>({0, 6, 7}).count(state) > 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}