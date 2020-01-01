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

const int A = 1000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<bool> prime(A + A + 1, true);
  prime[1] = false;
  for (int i = 2; i <= A + A; i++) {
    if (prime[i]) {
      for (int j = i + i; j <= A + A; j += i) {
        prime[j] = false;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) {
      if (prime[a[j] + a[i]]) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
 // debug(g);
  vector<int> ans;
  vector<vector<bool>> chk(n, vector<bool>(n));
  while (true) {
    vector<int> pa(n, -1);
    vector<int> pb(n, -1);
    vector<int> was(n);
    int iter = 0;
    function<bool(int)> Dfs = [&](int v) {
      was[v] = iter;
      for (int u : g[v]) {
        if (!chk[v][u] && pb[u] == -1) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      for (int u : g[v]) {
        if (!chk[v][u] && was[pb[u]] != iter && Dfs(pb[u])) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      return false;
    };
    int match = 0;
    while (true) {
      iter++;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        cnt += (pa[i] == -1 && Dfs(i));
      }
      if (cnt == 0) {
        break;
      }
      match += cnt;
    }
 //   debug(match);
 //   debug(pa);
 //   debug(pb);
    if (match < n) {
      break;
    }
    ans.push_back(a[pa[0]]);
    chk[0][pa[0]] = true;
  }
  if (ans.empty()) {
    cout << -1 << '\n';
  } else {
    sort(ans.begin(), ans.end());
    for (int x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}
