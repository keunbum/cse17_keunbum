#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int a[N];
pair<int, int> ans[N];
int pp[N];
int stk[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int INF = (int) 2e9;
  int n;
  cin >> n;
  fill_n(ans, n, make_pair(-INF, -1));
  fill_n(pp, n, -1);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    auto c = make_pair(a[i], i);
    int p = (int) (lower_bound(ans, ans + cnt, c, [&](const auto &p, const auto &q) { return p.first < q.first; }) - ans);
    ans[p] = c;
    cnt += (int) (ans[cnt].first > -INF);
    if (p - 1 >= 0) {
      pp[ans[p].second] = ans[p - 1].second;
    }
  }
  pp[0] = -1;
  cout << cnt << '\n';
  int x = ans[cnt - 1].second;
  int top = 0;
  while (x != -1) {
    stk[top++] = a[x];
    x = pp[x];
  }
  for (int i = top - 1; i >= 0; i--) {
    if (i < top - 1) {
      cout << ' ';
    }
    cout << stk[i];
  }
  cout << '\n';
  return 0;
}
