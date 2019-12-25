#include <bits/stdc++.h>
#include <random>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
  const int N = (int) 1e5;
  const int MAX = (int) 1e6;
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 engine(seed);                    // MT19937 난수 엔진
	uniform_int_distribution<int> distribution(-MAX, MAX);       // 생성 범위
	auto generator = bind(distribution, engine);
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << generator();
	}
	cout << '\n';
	return 0;
}
