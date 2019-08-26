#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int e = 1;
	while (e <= n) {
		ans += n - e + 1;
		e *= 10;
	}
	cout << ans << '\n';
	return 0;
}
