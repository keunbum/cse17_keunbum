#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int ALPHA = 26;
const int HW = 110;

char s[HW][HW];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
      cin >> (s[i] + 1);
    }
    for (int i = 0; i < h + 2; i++) {
      s[i][0] = s[i][w + 1] = '.';
    }
    for (int j = 0; j < w + 2; j++) {
      s[0][j] = s[h + 1][j] = '.';
    }
    h += 2;
    w += 2;
    vector<bool> has_key(ALPHA, false);
    {
      string k;
      cin >> k;
      if (k != "0") {
        for (char c : k) {
          has_key[(int) (c - 'a')] = true;
        }
      }
    }
    vector<pair<int, int>> que;
    vector<vector<bool>> was(h, vector<bool>(w, false));
    vector<vector<pair<int, int>>> st(ALPHA);
    que.emplace_back(0, 0);
    was[0][0] = true;
    int ans = 0;
    for (int i = 0; i < (int) que.size(); i++) {
      for (int dir = 0; dir < 4; dir++) {
        int nx = que[i].first + DX[dir];
        int ny = que[i].second + DY[dir];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] != '*' && !was[nx][ny]) {
          was[nx][ny] = true;
          if (s[nx][ny] >= 'a' && s[nx][ny] <= 'z') {
            int nth = (int) (s[nx][ny] - 'a');
            has_key[nth] = true;
            while (!st[nth].empty()) {
              que.emplace_back(st[nth].back().first, st[nth].back().second);
              st[nth].pop_back();
            }
          } else
          if (s[nx][ny] == '$') {
            ++ans;
          } else
          if (s[nx][ny] >= 'A' && s[nx][ny] <= 'Z' && !has_key[(int) (s[nx][ny] - 'A')]) {
            st[(int) (s[nx][ny] - 'A')].emplace_back(nx, ny);
            continue;
          }
          que.emplace_back(nx, ny);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
