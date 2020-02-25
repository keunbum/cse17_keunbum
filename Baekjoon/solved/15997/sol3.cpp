#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<string, int> mp;
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    mp[s] = i;
  }
  vector<vector<double>> prob(6, vector<double>(3));
  vector<int> x(6);
  vector<int> y(6);
  for (int i = 0; i < 6; i++) {
    string a, b;
    cin >> a >> b >> prob[i][0] >> prob[i][1] >> prob[i][2];
    x[i] = mp[a];
    y[i] = mp[b];
  }
  const int ADD[3] = {3, 1, 0};
  vector<int> score(4, 0);
  vector<double> ans(4, 0.0);
  function<void(int, double)> Dfs = [&](int id, double acc_prob) {
    if (id == 6) {
      map<int, int> score_cnt;
      for (int i = 0; i < 4; i++) {
        ++score_cnt[-score[i]];
      }
      int foo = 2;
      for (auto it = score_cnt.begin(); foo > 0; it++) {
        int n = it->second;
        int r = min(foo, n);
        for (int i = 0; i < 4; i++) {
          if (-score[i] == it->first) {
            ans[i] += acc_prob * r / n;
          }
        }
        foo -= r;
      }
      return;
    }
    for (int i = 0; i < 3; i++) {
      score[x[id]] += ADD[i];
      score[y[id]] += ADD[2 - i];
      Dfs(id + 1, acc_prob * prob[id][i]);
      score[x[id]] -= ADD[i];
      score[y[id]] -= ADD[2 - i];
    }
  };
  Dfs(0, 1.0);
  cout << fixed << setprecision(17);
  for (int i = 0; i < 4; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
