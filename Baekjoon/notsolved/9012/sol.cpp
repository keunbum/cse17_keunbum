#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    char stk[50];
    int top = 0;
    bool ok = true;
    for (char c : s) {
      if (c == '(') {
        stk[top++] = c;
      } else {
        if (top > 0 && stk[top - 1] == '(') {
          top--;
        } else {
          ok = false;
          break;
        }
      }
    }
    cout << (top == 0 && ok ? "YES" : "NO") << '\n';
  }
  return 0;
}