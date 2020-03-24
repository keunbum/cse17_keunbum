#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int N, M;
int ans = INF;

char in[105][105];
pii nxt[105][105][4];
int getdis(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void aa(int lvl, pii pr, pii pb, int prv) {
	if (lvl == 10) return;

	for (int i = 0; i < 4; i++) {
		if (i == prv) continue;
		int nrx = nxt[pr.first][pr.second][i].first;
		int nry = nxt[pr.first][pr.second][i].second;
		int nbx = nxt[pb.first][pb.second][i].first;
		int nby = nxt[pb.first][pb.second][i].second;

		if (in[nbx][nby] == 'O') continue;
		if (in[nrx][nry] == 'O') {
			ans = min(ans, lvl + 1);
			return;
		}
		if (pii(nrx, nry) == pii(nbx, nby)) {
			nbx -= "1102"[i] - '1';
			nby -= "0211"[i] - '1';
			if (getdis(pii(nrx, nry), pr) > getdis(pii(nrx, nry), pb)) {
				swap(nbx, nrx);
				swap(nby, nry);
			}
		}
		aa(lvl + 1, pii(nrx, nry), pii(nbx, nby), i);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	
	int i, j, k, l;
	for (i = 0; i < N; i++) scanf("%s", in[i]);

	pii pr, pb;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (in[i][j] != 'R' && in[i][j] != 'B') continue;
			if (in[i][j] == 'R') pr = pii(i, j);
			if (in[i][j] == 'B') pb = pii(i, j);
			in[i][j] = '.';
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (in[i][j] == 'O' || in[i][j] == '#') continue;
			for (k = 0; k < 4; k++) {
				int dx = "1102"[k] - '1';
				int dy = "0211"[k] - '1';
				for (l = 1;; l++) if (in[i + l*dx][j + l*dy] == '#' || in[i + l*dx][j + l*dy] == 'O') break;
				if (in[i + l*dx][j + l*dy] == '#') l--;
				nxt[i][j][k] = pii(i + l*dx, j + l*dy);
			}
		}
	}
	aa(0, pr, pb, -1);
	if (ans == INF) ans = -1;
	return !printf("%d\n", ans);
}