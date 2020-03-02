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
  int w, h, n, k;
  cin >> w >> h >> n >> k;
  debug(w, h, n, k);
  vector<pair<int, int>> ks;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ks.emplace_back(y - x, x + y);
  }
  auto IsIn = [&](int st, int mid, int end) {
    return st <= mid && mid <= end;
  };
  auto Push = [&](int a, int b) {
    int x = (b - a) / 2;
    int y = (a + b) / 2;
    for (int dir = 0; dir < 5; dir++) {
      int nx = x + "12101"[dir] - '1';
      int ny = y + "11210"[dir] - '1';
      int k1 = ny - nx;
      int k2 = nx + ny;
      if (IsIn(0, k1 + k2, h + h) && IsIn(0, k2 - k1, w + w)) {
        ks.emplace_back(k1, k2);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a, b, c, d;
      tie(a, b) = ks[i];
      tie(c, d) = ks[j];
      Push(a, d);
      Push(c, b);
    }
  }
  int ans = 0;
  int ans_x = -1;
  int ans_y = -1;
  for (int i = 0; i < (int) ks.size(); i++) {
    int ia, ib;
    tie(ia, ib) = ks[i];
    debug(ia, ib, (ib - ia) / 2, (ia + ib) / 2);
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      int ja, jb;
      tie(ja, jb) = ks[j];
      bool is_in = false;
      if (IsIn(ia, ja, ia + k) && IsIn(ib, jb, ib + k)) {
        is_in = true;
        ++cnt;
      }
      debug(ja, jb, (jb - ja) / 2, (ja + jb) / 2, is_in);
    }
    debug(cnt);
    if (cnt > ans) {
      ans = cnt;
      ans_x = (ib - ia) / 2;
      ans_y = (ia + ib ) / 2 + k / 2;
    }
  }
  cout << ans_x << ' ' << ans_y << '\n';
  cout << ans << '\n';
  return 0;	
}
