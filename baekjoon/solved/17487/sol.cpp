#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  int L = 0, R = 0;
  int r = 0;
  for (char c : s) {
    if (c == ' ') {
      r++;
      continue;
    }
    if (c >= 'A' && c <= 'Z') {
      r++;
      c += -'A' + 'a';
    }
    bool is_l = false;
    for (char t : "qwertyasdfgzxcvb") {
      if (t == c) {
        is_l = true;
        break;  
      }
    }
    is_l ? L++ : R++;
  }
  while (r--) {
    L <= R ? L++ : R++;
  }
  cout << L << ' ' << R << '\n';
  return 0;
}
