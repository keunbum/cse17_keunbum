#include <iostream>
#include <vector>

using namespace std;

const int inf = (int) 2e9;
const int MAX_N = 10000;

struct edge {
  int from, to, c, f;
};

int N, M;
int n, st, fin;
string a[100];
vector<vector<int>> g(MAX_N);
vector<edge> edges;
vector<int> q, d, ptr;

inline isnok(int x, int y) {
  return x < 0 || x >= N || y < 0 || y >= M || a[x][y] == '#'; 
}

void add(int from, int to, int cap) {
  g[from].push_back((int) edges.size());
  edges.push_back({from, to, 1, 0});
  g[to].push_back((int) edges.size());
  edges.push_back({to, from, 0, 0});
}

int max_flow() {
  int flow = 0;
  while (expath()) {
    
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char c = a[i][j];
      if (c == '#') continue;
      n += 2;
      int u = 2 * (i * N + j);
      int v = u + 1;
      if (c == 'K') { st = v; }
      if (c == 'H') { fin = u; }
      add(u, v, 1);
      for (int k = 0; k < 4; k++) {
        int x = u + "2101"[k] - '1';
        int y = v + "1210"[k] - '1';
        if (isnok(x, y)) continue;
        x = 2 * (x * N + y);
        y = x + 1;
        add(v, x, 1);
      }
    }
  }
  int ans = max_flow();
  cout << (ans == 0 ? -1 : ans) << '\n';
  return 0;
}