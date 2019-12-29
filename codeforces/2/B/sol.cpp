#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

const int inf = (int) 1e9;
const int N = 1000;

int n;
int a[N][N];
int dp[N][N];
char p[N][N];
int DX[128];
int DY[128];

int Cnt(int x, int y) {
	int cnt = 0;
	while (x % y == 0) {
		x /= y;
		cnt++;
	}
	return cnt;
}

pair<int, string> Get(int q) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == 0) {
				dp[i][j] = Cnt(a[i][j], q);
//				cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
				continue;
			}
			int cnt = Cnt(a[i][j], q);
			if (j > 0 && dp[i][j] > cnt + dp[i][j - 1] && a[i][j - 1] != 0) {
				dp[i][j] = cnt + dp[i][j - 1];
				p[i][j] = 'R';
			}
			if (i > 0 && dp[i][j] > cnt + dp[i - 1][j] && a[i - 1][j] != 0) {
				dp[i][j] = cnt + dp[i - 1][j];
				p[i][j] = 'D';
			}
//			cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
		}
	}
	int x = n - 1;
	int y = n - 1;
	string path;
	while (p[x][y] != 0) {
		path.push_back(p[x][y]);
		int px = x;
		int py = y;
		x = px + DX[p[px][py]];
		y = py + DY[p[px][py]];
	}
	reverse(path.begin(), path.end());
	return make_pair(dp[n - 1][n - 1], path);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  DX['D'] = -1;
  DY['R'] = -1;
  cin >> n;
  int mn0 = inf;
  string path0;
  bool chk = false;
  for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				a[i][j] = 10;
				if (!chk) {
					chk = true;
					mn0 = 1;
					path0 += string(i, 'D') + string(j, 'R');
					path0 += string(n - 1 - i, 'D') + string(n - 1 - j, 'R');
				}
			}
		}
	}
	int mn2;
	int mn5;
	string path2;
	string path5;
	tie(mn2, path2) = Get(2);
	tie(mn5, path5) = Get(5);
	int mn;
	string path;
	if (mn2 < mn5) {
		mn = mn2;
		path = path2;
	} else {
		mn = mn5;
		path = path5;
	}
	if (mn > mn0) {
		mn = mn0;
		path = path0;
	}
	cout << mn << '\n' << path << '\n';
  return 0;
}
