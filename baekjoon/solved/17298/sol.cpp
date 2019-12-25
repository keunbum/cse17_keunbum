#include <iostream>

using namespace std;

const int N = (int) 1e6;

pair<int, int> stk[N + 1];
int a[N + 1], ans[N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int top = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    while (top > 0 && a[i] > stk[top - 1].first) {
      ans[stk[top - 1].second] = a[i];
      top--;
    }
    stk[top++] = make_pair(a[i], i);
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << (ans[i] ? ans[i] : -1);
  }
  cout << '\n';
  return 0;
}