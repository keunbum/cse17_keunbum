#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	vector<int> a;
	while (cin >> x) {
		a.push_back(x);
	}
	function<void(int, int)> Dfs = [&](int b, int e) {
		if (b != e) {
			int i;
			for (i = b + 1; i <= e; i++) {
				if (a[i] > a[b]) {
					break;
				}
			}
			if (b + 1 <= i - 1) Dfs(b + 1, i - 1);
			if (i <= e) Dfs(i, e);
		}
		cout << a[b] << '\n';
	};
	int n = (int) a.size();
	Dfs(0, n - 1);
	return 0;
}
