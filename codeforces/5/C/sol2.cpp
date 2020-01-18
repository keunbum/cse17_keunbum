#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = (int) 1e6;

int stk[N];
bool good[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(good, true, sizeof(good));
  string s;
  cin >> s;
  int top = 0;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') stk[top++] = i; else
    if (top > 0) top--;
    else good[i] = false;
  }
  int ans = 0;
  int cnt = 1;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (good[i] && s[i] == ')') {
      cur++;
      if (cur > ans) {
        ans = cur;
        cnt = 1;
      } else
      if (cur == ans) {
        cnt++;
      }
    } else {
      if (s[i] == ')') {
        cur = 0;
      }
    }
  }
  cout << ans << ' ' << cnt << '\n';
  return 0;
}
