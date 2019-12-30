#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e6;

char stk[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int top = 0;
  for (char c : s) {
    stk[top++] = c;
    if (top >= 4) {
      bool ok = true;
      if (strncmp(stk + top - 4, "PPAP", 4)) {
        ok = false;
      }
      if (ok) {
        top -= 3;
      }
    }
  }
  cout << (top == 1 && stk[0] == 'P' ? "PPAP" : "NP") << '\n';
  return 0;
}
