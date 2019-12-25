#include <iostream>

using namespace std;

pair<char, pair<int, int>> stk[34];

inline int getv(char c) {
  if (c == ')') return 2;
  else return 3;
}

inline bool ismatch(char a, char b) {
  if (a == '(' && b == ')') return true;
  if (a == '[' && b == ']') return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int top = 0;
  int pre = 0;
  int ans = 0;
  for (char c : s) {
    if (c == '(' || c == '[') {
      stk[top++] = make_pair(c, make_pair(pre, 1));
      pre = 0;
    } else {
      if (!ismatch(stk[top - 1].first, c)) { cout << 0 << '\n'; return 0; }
      ans = stk[top - 1].second.first + stk[top - 1].second.second * getv(c);
      top--;
      stk[top - 1].second.second = ans;
      pre = ans;
    }
  }
  cout << (top ? 0 : ans) << '\n';
  return 0;
}