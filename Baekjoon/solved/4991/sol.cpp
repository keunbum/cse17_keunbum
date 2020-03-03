#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MAXN = 410;
const int inf = (int) 1e9;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

int qx[MAXN];
int qy[MAXN];

int RunBfs(int sx, int sy, int ex, int ey, vector<string>& s) {
  int h = (int) s.size();
  int w = (int) s[0].size();
  vector<vector<int>> dist(h, vector<int>(w, -1));
  int b = 0;
  int e = 1;
  qx[0] = sx;
  qy[0] = sy;
  dist[sx][sy] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] != 'x' && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
        qx[e] = nx;
        qy[e] = ny;
        ++e;
      }
    }
    ++b;
  }
  return (dist[ex][ey] == -1 ? inf : dist[ex][ey]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w + h == 0) {
      break;
    }
    vector<string> s(h);
    int sx = -1;
    int sy = -1;
    vector<pair<int, int>> a;
    for (int i = 0; i < h; i++) {
      cin >> s[i];
      for (int j = 0; j < w; j++) {
        if (s[i][j] == 'o') {
          sx = i;
          sy = j;
        } else
        if (s[i][j] == '*') {
          a.emplace_back(i, j);
        }
      }
    }
    int n = (int) a.size();
    debug(sx, sy);
    debug(n, a);
    if (n == 0) {
      cout << "-1\n";
      continue;
    }
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        adj[i][j] = adj[j][i] = RunBfs(a[i].first, a[i].second, a[j].first, a[j].second, s);
      } 
    }
    for (auto& v : adj) {
      debug(v);
    }
    int ans = inf;
    vector<vector<int>> dp(n, vector<int>(1 << n, inf));
    for (int i = 0; i < n; i++) {
      dp[i][1 << i] = RunBfs(sx, sy, a[i].first, a[i].second, s);
    }
    for (int t = 1; t < (1 << n); t++) {
      for (int i = 0; i < n; i++) {
        if ((t & (1 << i)) > 0) {
          for (int j = 0; j < n; j++) {
            if (i != j && (t & (1 << j)) > 0) {
              dp[i][t] = min(dp[i][t], dp[j][t ^ (1 << i)] + adj[j][i]);
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      debug(dp[i][(1 << n) - 1]);
      ans = min(ans, dp[i][(1 << n) - 1]);
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
