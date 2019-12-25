#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	function<long long(int, int)> Dfs = [&](int x, int k) {
//		cerr << x << ' ' << k << '\n';
		if (x == 0) {
			return 0LL;
		}
		if (x >= k) {
			return Dfs(x - k, k + 1) + 1LL;
		}
		return Dfs(x, 1);
	};
	cout << Dfs(n, 1) << '\n';
	return 0;
}
