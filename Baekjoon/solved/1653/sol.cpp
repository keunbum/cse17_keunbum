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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<bool> chk(n, false);
  function<void(vector<int>&, const int, int, vector<vector<int>>&)> Dfs = [&](vector<int>& v, const int val, int sum, vector<vector<int>>& vs) {
    if (v.size() == 5) {
      if (val == sum) {
        vs.push_back(v);
      }
      return;
    }
    int d = (int) v.size() + 1;
    for (int i = 0; i < n; i++) {
      if (!chk[i] && sum + d * a[i] <= val) {
        chk[i] = true;
        v.push_back(a[i]);
        Dfs(v, val, sum + d * a[i], vs);
        v.pop_back();
        chk[i] = false;
      }
    }
    v.push_back(0);
    Dfs(v, val, sum, vs);
    v.pop_back();
  };
  vector<long long> ss;
  ss.push_back(0LL);
  for (int val = 1; val <= 115; val++) {
    vector<int> v;
    vector<vector<int>> vs;
    Dfs(v, val, 0, vs);
    int sz = (int) vs.size();
    if (sz <= 1) {
      continue;
    }
//    sort(vs.begin(), vs.end());
//    debug(val);
//    debug(vs);
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        {
          int bit_a = 0;
          for (int x = 0; x < (int) vs[i].size(); x++) {
            if (vs[i][x] > 0) bit_a |= (1 << vs[i][x]);
          }
          int bit_b = 0;
          for (int y = 0; y < (int) vs[j].size(); y++) {
            if (vs[j][y] > 0) bit_b |= (1 << vs[j][y]);
          }
          if (bit_a & bit_b) {
            continue;
          }
        }
        long long r = 0LL;
        for (int x = (int) vs[i].size(); x >= 0; x--) {
          r = r * 10 + vs[i][x];
        }
        for (int y = 0; y < (int) vs[j].size(); y++) {
          r = r * 10 + vs[j][y];
        }
//        debug(vs[i], vs[j], r);
        ss.push_back(r);
      }
    }
  }
  int k;
  cin >> k;
  sort(ss.begin(), ss.end());
//  debug(ss);
  int ssz = (int) ss.size();
//  debug(ssz);
  if (k <= ssz) {
    cout << ss[k] << '\n';
  } else {
    cout << ss.back() << '\n';
  }
//  cerr << (float) clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
