#include <iostream>
#include <cassert>

using namespace std;

const int N = (int) 1e6;

char stk[N];
int pre[N];
int ans[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int top = 0;
  int cnt = 0;
  char c;
  while (cin >> c) {
    if (c == '(') {
      stk[top] = '(';
      pre[top] = cnt;
      ++top;
      cnt = 0;
    } else {
      if (top > 0 && stk[top - 1] == '(') {
        cnt += pre[top - 1] + 2;
        top--;
      } else {
        ans[cnt]++;
        cnt = 0;
      }
    }
  }
  stk[top] = '(';
  pre[top] = cnt;
  ++top;
  cnt = 0;
  while (top > 0) {
    ans[pre[--top]]++;
  }
  for (int i = N; i >= 1; i--) {
    if (ans[i] > 0) {
      cout << i << ' ' << ans[i] << '\n';
      return 0;
    }
  }
  cout << "0 1" << '\n';
  return 0;
}
