#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int stk[30], val[30], top = 0, ans = 0, in, cur = 0;
  char c;
  while (cin >> c) {
    if (c == '(' || c == '[') { // left
      stk[top] = c;
      in = 1;
      ans += cur;
      cur = 0;
      if (c == '(') val[top] = 2;
      else val[top] = 3;
      top++;
      cout << "ans = " << ans << '\n'; 
    } else {// right
      if (c == ')') {
        if (top <= 0 || stk[top - 1] != '(') {
          break;
        } 
      } else {
        if (top <= 0 || stk[top - 1] != '[') {
          break;
        }
      }
      cur = val[--top] * in;
      in = cur;
    }
  }
  cout << (top == 0 ? ans : 0) << '\n';
  return 0;
}
