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

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int MAX = 2510;

int qx[MAX];
int qy[MAX];

void RunBfs(const vector<string>& s, int sx, int sy, vector<vector<int>>& dist) {
  int r = (int) s.size();
  int c = (int) s[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      dist[i][j] = -1;
    }
  }
  int b = 0, e = 1;
  qx[0] = sx;
  qy[0] = sy;
  dist[sx][sy] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] != '*' && s[nx][ny] != 'X' && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
        qx[e] = nx;
        qy[e] = ny;
        ++e;
      }
    }
    ++b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<string> s(r);
  for (int i = 0; i < r; i++) {
    cin >> s[i];
  }
  int sx = -1, sy = -1;
  int fx = -1, fy = -1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (s[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (s[i][j] == 'D') {
        fx = i;
        fy = j;
      }
    }
  }
  vector<vector<int>> dist(r, vector<int>(c));
  RunBfs(s, sx, sy, dist);
  vector<vector<int>> dist_start = dist;
  if (dist[fx][fy] == -1) {
    cout << "KAKTUS" << '\n';
    return 0;
  }
  vector<vector<int>> dist_flood(r, vector<int>(c, -1));
  vector<string> g = s;
  g[fx][fy] = 'X';
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (g[i][j] == '*') {
        RunBfs(g, i, j, dist);
        debug(dist);
        for (int x = 0; x < r; x++) {
          for (int y = 0; y < c; y++) {
            if (dist_flood[x][y] == -1 || (dist[x][y] != -1 && dist_flood[x][y] > dist[x][y])) {
              dist_flood[x][y] = dist[x][y];
            }
          }
        }
      }
    }
  }
  debug(dist_start);
  debug(dist_flood);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (dist_flood[i][j] != -1 && dist_flood[i][j] <= dist_start[i][j]) {
        g[i][j] = '*';
      }
    }
  }
  g[fx][fy] = 'D';
  debug(g);
  RunBfs(g, sx, sy, dist);
  if (dist[fx][fy] == -1) {
    cout << "KAKTUS" << '\n';
  } else {
    cout << dist[fx][fy] << '\n';
  }
  return 0;
}
