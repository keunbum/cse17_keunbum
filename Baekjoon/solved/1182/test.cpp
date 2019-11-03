#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 5;
	const int S = 10;
	cout << N << ' ' << S << '\n';
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			cout << ' ';
		}
		int t = rng() % 10;
		cout << t - 5;
	}
	cout << '\n';
	return 0;
}
