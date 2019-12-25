#include <bits/stdc++.h>

using namespace std;

int F(vector<vector<int>>& v) {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res = res * 9 + v[i][j];
		}
	}
	return res;
}

vector<vector<int>> Inv(int n) {
	vector<vector<int>> res(3, vector<int>(3));
	for (int i = 8; i >= 0; i--) {
		int x = i / 3;
		int y = i % 3;
		res[x][y] = n % 9;
		n /= 9;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> g(3, vector<int>(3));
	for (int i = 0; i < 8; i++) {
		int x = i / 3;
		int y = i % 3;
		g[x][y] = i + 1;
	}
	vector<vector<int>> a(3, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	const int DX[4] = {1, 0, -1, 0};
	const int DY[4] = {0, 1, 0, -1};
	map<int, int> m;
	queue<int> q;
	int aa = F(a);
	q.push(aa);
	m[aa] = 0;
	bool ok = false;
	while (!q.empty()) {
		int uu = q.front();
		q.pop();
		auto u = Inv(uu);
		if (u == g) {
			ok = true;
			cout << m[uu] << '\n';
			break;
		}
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (u[x][y] == 0) {
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + DX[dir];
						int ny = y + DY[dir];
						if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
							swap(u[x][y], u[nx][ny]);
							int vv = F(u);
							if (m.count(vv) == 0) {
								m[vv] = m[uu] + 1;
								q.push(vv);
							}
							swap(u[x][y], u[nx][ny]);
						}
					}
				}
			}
		}
	}
	if (!ok) {
		cout << "-1" << '\n';
	}
	return 0;
}
