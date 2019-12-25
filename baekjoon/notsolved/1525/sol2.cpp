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

const int N = (int) 4e5;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

bool was[N];
int dist[N];
int q[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> fact(9);
	fact[0] = 1;
	for (int i = 1; i < 9; i++) {
		fact[i] = fact[i - 1] * i;
	}
//	debug(fact);
	vector<int> a(9);
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
//	debug(a);
	auto F = [&](vector<int>& a, int n) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					cnt++;
				}
			}
			res += cnt * fact[n - 1 - i];
		}
		return res;
	};
	auto Inv = [&](int x, int n) {
		vector<bool> chk(10);
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			int t = x / fact[n - 1 - i];
			x = x % fact[n - 1 - i];
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (!chk[j]) {
					if (cnt == t) {
						res[i] = j;
						chk[j] = true;
						break;
					}
					cnt++;
				}
			}
		}
		return res;
	};
	int st = F(a, 9);
//	debug(st);
	for (int i = 0; i < 9; i++) {
		a[i] = (i + 1) % 9;
	}
//	debug(a);
	int en = F(a, 9);
	int b = 0, e = 1;
	q[0] = st;
	dist[st] = 0;
	was[st] = true;
	while (b < e) {
		auto v = Inv(q[b], 9);
//		debug(v);
		auto u(v);
		int x, y, A;
		for (int i = 0; i < 9; i++) {
			if (v[i] == 0) {
				A = i;
				x = i / 3;
				y = i % 3;
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + DX[dir];
			int ny = y + DY[dir];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				int B = 3 * nx + ny;
				swap(u[A], u[B]);
				int uu = F(u, 9);
				swap(u[A], u[B]);
				if (!was[uu]) {
					q[e] = uu;
					was[uu] = true;
					dist[uu] = dist[q[b]] + 1;
					++e;
				}
			}
		}
		++b;
	}
	cout << (was[en] ? dist[en] : -1) << '\n';
	return 0;
}
