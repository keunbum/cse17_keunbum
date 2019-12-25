#include <iostream>
#include <string>

using namespace std;

inline bool is_alpha(char c) {
  return c >= 'A' && c <= 'Z';
}
inline bool is_above(char c) {
  return c == '*' || c == '/';
}

// Save it and do it later
// ==> Stack

// The priority of the operation is determined by the
// priority between the operators and 
// the position of the pair of parentheses.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string ans, stk;
  for (int i = 0; i < (int) s.size(); i++) {
    char c = s[i];
    if (is_alpha(c)) { ans.push_back(c); continue;}
    if (c == ')') {
      while (stk.back() != '(') {
        ans.push_back(stk.back());
        stk.pop_back();
      }
      stk.pop_back();
      continue;
    }
    if (c != '(') {
      while (!stk.empty()) {                                                   
        if (stk.back() == '(' || (is_above(c) && !is_above(stk.back()))) break;
        ans.push_back(stk.back());                                             
        stk.pop_back();                                                        
      }                                                                        
    }
    stk.push_back(c);
  }
  while (!stk.empty()) {
    ans.push_back(stk.back());
    stk.pop_back();
  }
  cout << ans << '\n';
  return 0;
}