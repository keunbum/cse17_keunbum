#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> con(4);
  for (int i = 0; i < 4; i++) {
    cin >> con[i];
  }
  double prob[6][3];
  vector<pair<int, int>> e(6);
  for (int i = 0; i < 6; i++) {
    string a, b;
    cin >> a >> b >> prob[i][0] >> prob[i][1] >> prob[i][2];
    for (int j = 0; j < 4; j++) {
      if (con[j] == a) e[i].first = j; else
      if (con[j] == b) e[i].second = j;
    }
  }
  const int SCORE[3] = {3, 1, 0};
  vector<double> ans(4, 0.0);
  vector<int> score(4, 0);
  function<void(int, double)> Dfs = [&](int id, double acc_p) {
    if (id == 6) {
      vector<pair<int, int>> v;
      for (int i = 0; i < 4; i++) v.emplace_back(score[i], i);
      v.emplace_back(-1, 4);
      sort(v.rbegin(), v.rend());
      int st = 0;
      int foo = 2;
      for (int i = 1; i < 5 && foo > 0; i++) {
        if (v[i].first == v[i - 1].first) {
          continue;
        }
        int n = i - st;
        int r = min(foo, n);
        double rate = (double) r / n;
        for (int j = st; j < i; j++) {
          ans[v[j].second] += acc_p * rate;
        } 
        st = i;
        foo -= r;
      }
      return;
    }
    int x, y;
    tie(x, y) = e[id];
    for (int i = 0; i < 3; i++) {
      score[x] += SCORE[i];
      score[y] += SCORE[2 - i];
      Dfs(id + 1, acc_p * prob[id][i]);
      score[x] -= SCORE[i];
      score[y] -= SCORE[2 - i];
    }
  };
  Dfs(0, 1.0);
  cout << fixed << setprecision(17);
  for (int i = 0; i < 4; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
