#include <bits/stdc++.h>

using namespace std;

mt19937 rng(1234123651235L);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = (int) 1e6;
	const int W = (int) 1e5;
	cout << N << ' ' << W << '\n';
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			cout << ' ';
		}
		int t = rng() % (N - 1) + 1;
		assert(t >= 0 && t < N);
		cout << t;
	}
	cout << '\n';
	return 0;
}
