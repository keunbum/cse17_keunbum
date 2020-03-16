#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    string s;
    getline(cin, s);
    if (s == ".") break;
    vector<char> st;
    bool ok = true;
    for (char c : s) {
      if (c == '[' || c == '(') st.push_back(c); else
      if (c == ']') {
        if (st.empty() || st.back() != '[') { ok = false; break; }
        st.pop_back();
      } else
      if (c == ')') {
        if (st.empty() || st.back() != '(') { ok = false; break; }
        st.pop_back();
      }
    }
    if (!st.empty()) ok = false;
    cout << (ok ? "yes" : "no") << '\n';
  }
  return 0;
}
