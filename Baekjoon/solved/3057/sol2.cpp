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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  auto IsIn = [&](int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w;
  };
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  vector<vector<vector<long long>>> mask(h, vector<vector<long long>>(w, vector<long long>(4, 0)));
  {
    for (int i = h - 1; i >= 0; i--) {
      for (int j = w - 1; j >= 0; j--) {
        for (int dir = 0; dir < 2; dir++) {
          int pi = i + DX[dir];
          int pj = j + DY[dir];
          if (IsIn(pi, pj)) {
            mask[i][j][dir] = mask[pi][pj][dir] << 1;
          } else {
            mask[i][j][dir] = 0;
          }
          mask[i][j][dir] |= (s[i][j] == '1');
        }
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        for (int dir = 2; dir < 4; dir++) {
          int pi = i + DX[dir];
          int pj = j + DY[dir];
          if (IsIn(pi, pj)) {
            mask[i][j][dir] = mask[pi][pj][dir] << 1;
          } else {
            mask[i][j][dir] = 0;
          }
          mask[i][j][dir] |= (s[i][j] == '1');
        }
      }
    }
    debug(mask);
  }
  auto Check = [&](int x, int y, int n) {
    if (x < 0 || y < 0 || x + n >= h || y + n >= w) {
      return false;
    }
    for (int dir = 0; dir < 2; dir++) {
      int xa = x;
      int ya = y;
      int xb = x + n;
      int yb = y + n;
      for (int s = n + 1; s > 0; s -= 64) {
        long long x = mask[xa][ya][dir];
        long long y = mask[xb][yb][dir + 2];
        if (s >= 64) {
          if (x ^ y) {
            return false;
          }
        } else {
          if ((x ^ y) & ((1LL << s) - 1)) {
            return false;
          }
        }
        xa += 64 * DX[dir]; ya += 64 * DY[dir];
        xb -= 64 * DX[dir]; yb -= 64 * DY[dir];
      }
    }
    return true;
  };
  int ans = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int rot = 0; rot < 2; rot++) {
        int max_l = min({i + 1, j + 1, h - i, w - j});
        if (2 * max_l + rot <= ans) {
          continue;
        }
        int n = rot;
        while (Check(i - n / 2, j - n / 2, n)) {
          n += 2;
        }
        ans = max(ans, n - 1);
      }
    }
  }
  cout << (ans > 1 ? ans : -1) << '\n'; 
  return 0;
}
