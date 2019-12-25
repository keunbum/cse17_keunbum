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
	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	vector<int> U;
	vector<int> V;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			U.push_back(A[i] + B[j]);
			V.push_back(C[i] + D[j]);
		}
	}
	auto Merge = [&](vector<int>& V) {
		vector<pair<int, int>> res;
		sort(V.begin(), V.end());
		int b = 0;
		int e = (int) V.size();
		for (int i = 0; i < e; i++) {
			if (i + 1 == e || V[i + 1] != V[b]) {
				res.emplace_back(V[b], i - b + 1);
				b = i + 1;
			}
		}
		return res;
	};
	auto u = Merge(U);
	auto v = Merge(V);
//	debug(u);
//	debug(v);
	long long ans = 0LL;
	int pu = 0;
	int usz = (int) u.size();
	int pv = (int) v.size() - 1;
	while (pu < usz && pv >= 0) {
		long long sum = (long long) u[pu].first + v[pv].first;
		if (sum == 0LL) {
			ans += (long long) u[pu].second * v[pv].second;
			pu++;
			pv--;
		} else
		if (sum < 0LL) {
			pu++;
		} else {
			pv--;
		}
	}
	cout << ans << '\n';
//	cerr << (double) clock() / CLOCKS_PER_SEC << '\n';
	return 0;
}
