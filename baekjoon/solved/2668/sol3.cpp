#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int deg[N], q[N], a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		deg[a[i]]++;
	}
	int b = 0, e = 0;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q[e++] = i;
		}
	}
	while (b < e) {
		int x = q[b++];
		if (--deg[a[x]] == 0) {
			q[e++] = a[x];
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (deg[i] > 0) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << '\n';
	}
	return 0;
}
