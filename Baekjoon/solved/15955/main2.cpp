#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> x[250005], y[250005];
pair<int, pair<int, int> > a[500005];
vector<pair<int, int> > g[250005];

int p[250005];
int d[250005];
int P[250005][20], Q[250005][20];

int f(int x) {
	return x == p[x] ? x : p[x] = f(p[x]);
}

void dfs(int x, int y) {
	int i;
	for (i = 1; i < 20; i++) {
		P[x][i] = P[P[x][i - 1]][i - 1];
		Q[x][i] = max(Q[x][i - 1], Q[P[x][i - 1]][i - 1]);
	}
	for (auto t : g[x]) if (t.first != y) {
		P[t.first][0] = x;
		Q[t.first][0] = t.second;
		d[t.first] = d[x] + 1;
		dfs(t.first, x);
	}
}

inline int query(int i, int j) {
	int l, r = 0;
	if (d[i] < d[j]) swap(i, j);
	for (l = 19; l >= 0; l--) if (d[i] - d[j] >> l) {
		r = max(r, Q[i][l]);
		i = P[i][l];
	}
	if (i == j) return r;
	for (l = 19; l >= 0; l--) if (P[i][l] != P[j][l]) {
		r = max(r, max(Q[i][l], Q[j][l]));
		i = P[i][l];
		j = P[j][l];
	}
	return max(r, max(Q[i][0], Q[j][0]));
}

int main() {
	int i, j, k, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i].first, &y[i].first);
		x[i].second = y[i].second = i;
		p[i] = i;
	}
	sort(x, x + n);
	sort(y, y + n);
	int an = 0;
	for (i = 1; i < n; i++) {
		a[an].first = x[i].first - x[i - 1].first;
		a[an].second.first = x[i].second;
		a[an].second.second = x[i - 1].second;
		an++;
		a[an].first = y[i].first - y[i - 1].first;
		a[an].second.first = y[i].second;
		a[an].second.second = y[i - 1].second;
		an++;
	}
	sort(a, a + an);
	for (i = 0; i < an; i++) if (f(a[i].second.first) != f(a[i].second.second)) {
		g[a[i].second.first].emplace_back(a[i].second.second, a[i].first);
		g[a[i].second.second].emplace_back(a[i].second.first, a[i].first);
		p[f(a[i].second.first)] = f(a[i].second.second);
	}
	dfs(0, 0);
	while (m--) {
		scanf("%d%d%d", &i, &j, &k);
		i--;
		j--;
		puts(query(i, j) > k ? "NO" : "YES");
	}
	return 0;
}