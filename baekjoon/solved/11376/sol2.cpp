#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct edge {
  int from;
  int to;
  int c;
  int f;
};

vector<vector<int>> g;
vector<edge> edges;
int n, m, N;
int st, fin;
int flow;
vector<int> ptr, d, q; // d is for depth(level), q is for queue(bfs)

void add(int from, int to, int forward_cap, int backward_cap) {
  g[from].push_back((int) edges.size());
  edges.push_back({from, to, forward_cap, 0});
  g[to].push_back((int) edges.size());
  edges.push_back({to, from, backward_cap, 0});
}

bool expath() {
  fill(d.begin(), d.end(), -1);
  q[0] = fin;
  d[fin] = 0;
  int beg = 0, end = 1;
  while (beg < end) {
    int i = q[beg++];
    for (int id : g[i]) {
      const edge &e = edges[id];
      const edge &back = edges[id ^ 1];
      if (back.c > back.f && d[e.to] == -1) {
        d[e.to] = d[i] + 1;
        if (e.to == st) {
          return true;
        }
        q[end++] = e.to;
      } 
    }
  }
  return false;
}

int dfs(int v, int w) {
  if (v == fin) {
    return w;
  }
  int &j = ptr[v];
  while (j >= 0) {
    int id = g[v][j];
    const edge &e = edges[id];
    if (e.c > e.f && d[e.to] == d[v] - 1) {
      int t = dfs(e.to, min(e.c - e.f, w));
      if (t > 0) {
        edges[id].f += t;
        edges[id ^ 1].f -= t;
        return t;
      }
    }
    j--;
  }
  return 0;
}

int max_flow() {
  while (expath()) {
    for (int i = 0; i < N; i++) {
      ptr[i] = (int) g[i].size() - 1;
    }
    int big_add = 0;
    while (true) {
      int add = dfs(st, numeric_limits<int>::max());
      if (add == 0) {
        break;
      }
      big_add += add;
    }
    if (big_add == 0) {
      break;
    }
    flow += big_add;
  }
  return flow;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  st = 0; fin = n + m + 1;
  N = n + m + 2;
  g.resize(N);
  ptr.resize(N);
  d.resize(N);
  q.resize(N);
  flow = 0;
  for (int i = 1; i <= n; i++) {
    add(st, i, 2, 0);
  }
  for (int i = 1; i <= m; i++) {
    add(n + i, fin, 1, 0); 
  }
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    while (t--) {
      int j;
      cin >> j;
      add(i, n + j, 1, 0);
    }
  }
  cout << max_flow() << '\n';
  return 0;
}