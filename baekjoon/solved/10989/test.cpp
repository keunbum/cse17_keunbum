#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e7;
const int MAXV = (int) 1e4;

mt19937 rng(58);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << N << '\n';
	for (int i = 0; i < N; i++) {
		cout << (rng() % MAXV + 1) << '\n';
	}
	return 0;
}
