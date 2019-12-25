#include <bits/stdc++.h>

using namespace std;

const int N = 100;

mt19937 rng(time(0));
uniform_int_distribution<int> d(1, N);
auto G = bind(d, rng);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << N << '\n';
	for (int i = 1; i <= N; i++) {
		cout << G() << '\n';
	}
	return 0;
}
