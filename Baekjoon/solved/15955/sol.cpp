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

struct Point {
  int x;
  int y;
  int id;
};

struct Edge {
  int from;
  int to;
  int cost;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  debug(n, tt);
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i].id = i;
  }
  vector<tuple<int, int, int, int>> q(tt);
  for (int qq = 0; qq < tt; qq++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    q[qq] = {x, y, z, qq};
  }
  vector<Edge> edges;
  sort(p.begin(), p.end(), [&](auto& pi, auto& pj) { return pi.x < pj.x; });
  for (int i = 0; i < n - 1; i++) {
    edges.push_back({p[i].id, p[i + 1].id, p[i + 1].x - p[i].x});
  }
  sort(p.begin(), p.end(), [&](auto& pi, auto& pj) { return pi.y < pj.y; });
  for (int i = 0; i < n - 1; i++) {
    edges.push_back({p[i].id, p[i + 1].id, p[i + 1].y - p[i].y});
  }
  sort(edges.begin(), edges.end(), [&](auto& ei, auto& ej) { return ei.cost < ej.cost; });
  sort(q.begin(), q.end(), [&](auto& qi, auto& qj) {
    return get<2>(qi) < get<2>(qj);
  });
  vector<int> pid(n);
  iota(pid.begin(), pid.end(), 0);
  function<int(int)> Get = [&](int v) {
    return v == pid[v] ? v : pid[v] = Get(pid[v]);
  };
  int next_id = 0;
  vector<bool> ans(tt);
  for (int qq = 0; qq < tt; qq++) {
    int A, B, X, QID;
    tie(A, B, X, QID) = q[qq];
//    debug(qq, A, B, X, QID);
    int id;
    for (id = next_id; id < (int) edges.size() && edges[id].cost <= X; id++) {
      const Edge& e = edges[id];
      pid[Get(e.from)] = Get(e.to);
    }
    next_id = id;
    ans[QID] = (Get(A) == Get(B));
  }
  for (bool ok : ans) {
    cout << (ok ? "YES" : "NO") << '\n';
  }
//  cerr << (double) clock() / CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
                              