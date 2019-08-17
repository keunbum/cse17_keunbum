#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int p[N], deg[N], deg_t[N], leaf_n[N], q[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (p[i] != -1) {
			deg[p[i]]++;
		}
	}
	int ans = 0;
	int beg = 0, end = 0;
	for (int i = 0; i < n; i++) {
		deg_t[i] = deg[i];
		if (deg[i] == 0) {
			q[end++] = i;
			ans++;
			leaf_n[i] = 1;
		}
	}
	while (beg < end) {
		int ch = q[beg++];
		int pa = p[ch];
		leaf_n[pa] += leaf_n[ch];
		if ((pa != -1) && (--deg[pa] == 0)) {
			q[end++] = pa;
		}
	}
	int del;
	cin >> del;
	ans -= leaf_n[del];
	if (p[del] != -1 && deg_t[p[del]] == 1) {
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
