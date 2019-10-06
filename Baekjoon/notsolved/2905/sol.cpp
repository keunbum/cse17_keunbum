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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  vector<int> sum(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i] = a[i];
    if (i > 0) {
      sum[i] += sum[i - 1];
    }
  }
  vector<int> mn(1 << (log2(n) + 1));
  function<void(int, int, int)> Build = [&](int x, int l, int r) {
    if (l == r) {
      mn[x] = a[l];
      return;
    }
    int y = (l + r) >> 1;
    Build(x + x, l, y);
    Build(x + x + 1, y + 1, r);
    mn[x] = min(mn[x + x], mn[x + x + 1]);
  };
  Build(1, 0, n - 1);
  function<long long(int, int, int, int, int)> Get = [&](int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return (long long) mn[x];
    }
    int y = (l + r) >> 1;
    long long res = 0;
    if (rr <= y) {
      res = Get(x + x, l, y, ll, rr);
    } else 
    if (ll < y) {
      res = Get(x + x + 1, y + 1, r, ll, rr);
    } else {
      res = min(Get(x + x, l, y, ll, rr), Get(x + x + 1, y + 1, r, ll, rr));
    }
    return res;   
  };
  cout << sum[w - 1] - Get(1, 0, n - 1, 0, w - 1) * w << '\n';
  cout << 1 << '\n';
  return 0;
}
