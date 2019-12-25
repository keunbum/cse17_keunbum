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

string to_string(const vector<bool>& v) {
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
string to_string(const bitset<N>& v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(const A& v) {
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
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C>& p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(const tuple<A, B, C, D>& p) {
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

inline int To(int x) {
  return ((abs(x) - 1) << 1) + (int) (x < 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + n), g_rev(n + n);
  while (m--) {
    int foo, bar;
    cin >> foo >> bar;
    int x = To(foo);
    int y = To(bar);
    g[x ^ 1].push_back(y);
    g_rev[y].push_back(x ^ 1);
    g[y ^ 1].push_back(x);
    g_rev[x].push_back(y ^ 1);
//    debug(x ^ 1, y);
//    debug(y ^ 1, x);
  }
  vector<int> order;
  vector<bool> was(n + n, false);
  function<void(int)> Dfs1 = [&](int v) {
    was[v] = true;
    for (int u : g[v]) {
      if (!was[u]) {
        Dfs1(u);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < n + n; i++) {
    if (!was[i]) {
      Dfs1(i);
    }
  }
  vector<int> c(n + n, -1);
  int cnt = 0;
  function<void(int)> Dfs2 = [&](int v) {
    for (int u : g_rev[v]) {
      if (c[u] == -1) {
        c[u] = c[v];
        Dfs2(u);
      }
    }
  };
  for (int i = n + n - 1; i >= 0; i--) {
    int v = order[i];
    if (c[v] == -1) {
      c[v] = cnt++;
      Dfs2(v);
    }
  }
  bool ok = true;
  for (int i = 0; i < n + n; i += 2) {
//    debug(c[i], c[i ^ 1]);
    if (c[i] == c[i ^ 1]) {
      ok = false;
      break;
    }
  }
  cout << (int) ok << '\n';
  return 0;
}
