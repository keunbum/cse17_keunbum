#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 2000;
	cout << N << '\n';
	mt19937 rng(58);
	const int MAX = (int) 1e5 + 1;
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << rng() % MAX;
	}
	cout << '\n';
	const int M = (int) 1e6;
	cout << M << '\n';
	for (int i = 0; i < M; i++) {
		int x = (rng() % N) + 1;
		int y = (rng() % N) + 1;
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
