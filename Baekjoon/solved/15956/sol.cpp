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
  string s;
  cin >> s;
  debug(s);
  int l = (int) s.size();
  int k = 0;
  map<string, int> mp;
  vector<string> inv;
  auto Insert = [&](string& t) {
    t = "";
    while (k < l && s[k] != '=' && s[k] != '!' && s[k] != '&') {
      t += s[k];
      ++k;
    }
    if (mp.find(t) == mp.end()) {
      mp[t] = (int) inv.size();
      inv.push_back(t);
    }
  };
  auto False = []() {
    cout << "0==1\n";
    exit(0);
  };
  auto IsInt = [](string& t) {
    return t[0] == '-' || (t[0] >= '0' && t[0] <= '9');
  };
  set<pair<int, int>> edges_a;
  set<pair<int, int>> edges_b;
  while (k < l) {
    string A;
    Insert(A);
    bool equal = (s[k] == '=');
    k += 2;
    string B;
    Insert(B);
    int a = mp[A];
    int b = mp[B];
    if (a > b) {
      swap(a, b);
    }
    if (equal) {
      if (a != b) {
        edges_a.emplace(a, b);
      }
    } else {
      if (a == b) {
        False();
      }
      if (!(IsInt(A) && IsInt(B))) {
        edges_b.emplace(a, b);
      }
    }
    k += 2;
  }
  int n = (int) inv.size();
  debug(n);
  debug(mp);
  debug(inv);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) {
    return v == p[v] ? v : p[v] = Get(p[v]);
  };
  for (const auto& e : edges_a) {
    int u, v;                 
    tie(u, v) = e;
    int u = Get(u);
    int u = Get(v);
    if (inv[u].size() < inv[v].size()) {
      p[v] = u;
    } else {
      p[u] = v;
    }
  }
  vector<int> c_int_cnt(n, 0);
  for (int i = 0; i < n; i++) {
    c_int_cnt[Get(i)] += (int) IsInt(inv[i]);
  }
  for (int i = 0; i < n; i++) {
    if (c_int_cnt[i] >= 2) {
      False();
    }
  }
  bool first = true;
  {
    set<pair<int, int>> new_edges_a;
    for (int i = 0; i < n; i++) {
      int I = Get(i);
      if (I != i) {
        new_edges_a.emplace(I, i);
      }
    }
    for (const auto& e : new_edges_a) {
      int u, v;
      tie(u, v) = e;
      if (!first) {
        cout << "&&";
      }
      first = false;
      cout << inv[u] << "==" << inv[v];
    }
  }
  {
    set<pair<int, int>> new_edges_b;
    for (const auto& e : edges_b) {
      int u, v;
      tie(u, v) = e;
      u = Get(u);
      v = Get(v);
      if (u == v) {
        False();
      }
      if (c_int_cnt[u] > 0 && c_int_cnt[v] > 0) {
        continue;
      }
      if (u > v) {
        swap(u, v);
      }
      new_edges_b.emplace(u, v);
    }
    for (const auto& e : new_edges_b) {
      int u, v;
      tie(u, v) = e;
      if (!first) {
        cout << "&&";
      }
      first = false;
      cout << inv[u] << "!=" << inv[v];
    }
  }
  if (first) {
    cout << "1==1";
  }
  cout << '\n';
  return 0;
}