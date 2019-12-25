#include <iostream>

using namespace std;

const int MAX = 500001;

int ans[MAX], height[MAX], stk[MAX];
int top = 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> height[i];
  }
  for (i = n; i >= 1; i--) {
    while (top > 1 && height[i] > height[stk[top - 1]]) {
      ans[stk[--top]] = i;
    }
    stk[top++] = i;
  }
  for (i = 1; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << ans[i] << '\n';
  return 0;
}