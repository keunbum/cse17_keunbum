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
  cout << fixed << setprecision(17);
  map<string, int> mp;
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    mp[s] = i;
//    debug(s, mp[s]);
  }
  double g[4][4][3];
  for (int i = 0; i < 6; i++) {
    string a, b;
    cin >> a >> b;
    double w, d, l;
    cin >> w >> d >> l;
    int A = mp[a];
    int B = mp[b];
    if (A > B) {
      swap(A, B);
      swap(w, l);
    }
    g[A][B][0] = w;
    g[A][B][1] = d;
    g[A][B][2] = l;
  }
  const int ORDER_X[6] = {0, 0, 0, 1, 1, 2};
  const int ORDER_Y[6] = {1, 2, 3, 2, 3, 3};
  const int SCORE[3] = {3, 1, 0};
  vector<int> acc_score(4, 0);
  vector<double> ans(4, 0.0);
  auto nCr = [&](int n, int r) {
    assert(n >= r && n >= 0 && n < 5);
    static int fact[5] = {1, 1, 2, 6, 24};
    return fact[n] / fact[n - r] / fact[r];
  };
  function<void(int, double)> Dfs = [&](int order, double prob) {
    if (prob < 1e-16) {
      return;
    }
    if (order == 6) {
//      debug(acc_score, prob);
      vector<int> idx(4);
      iota(idx.begin(), idx.end(), 0);
      sort(idx.begin(), idx.end(), [&](int i, int j) { return acc_score[i] > acc_score[j]; });
      vector<int> rank(4);
      vector<int> rank_sz(4, 0);
      for (int i = 0; i < 4; i++) {
        rank[idx[i]] = i;
        if (i > 0 && acc_score[idx[i]] == acc_score[idx[i - 1]]) {
          rank[idx[i]] = rank[idx[i - 1]];
        }
        ++rank_sz[rank[idx[i]]];
      }
      int surplus = 2;
      vector<double> add(4, 0.0);                           
      for (int rot = 0; rot < 2 && surplus > 0; rot++) {
        int n = rank_sz[rot];
        int r = min(surplus, n);
        double p = ((double) nCr(n - 1, r - 1)) / nCr(n, r);
//        debug(rot, n, r, p);
        for (int i = 0; i < 4; i++) {
          if (rank[i] == rot) {
            add[i] += prob * p;
          }
        }
        surplus -= rank_sz[rot];
      }
//      debug(add);
      for (int i = 0; i < 4; i++) {
        ans[i] += add[i];
      }                 
      return;
    }
    int x = ORDER_X[order];
    int y = ORDER_Y[order];
    for (int i = 0; i < 3; i++) {
      double next_prob = prob * g[x][y][i];
      acc_score[x] += SCORE[i];
      acc_score[y] += SCORE[2 - i];
      Dfs(order + 1, next_prob);
      acc_score[x] -= SCORE[i];
      acc_score[y] -= SCORE[2 - i];
    }
  };
  Dfs(0, 1.0);
  for (int i = 0; i < 4; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}