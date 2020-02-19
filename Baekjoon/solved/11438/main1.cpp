//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

vector <int> conn[100050];
int r[100050][20];
int dep[100050];

void DFS(int n) {
	int t, i;
	for (i = 0; i < conn[n].size(); i++) {
		t = conn[n][i];
		if (t == r[n][0]) continue;
		r[t][0] = n;
		dep[t] = dep[n] + 1;
		for (int j = 1; j < 20; j++) r[t][j] = r[r[t][j - 1]][j - 1];
		DFS(t);
	}
}

int upnode(int a, int x) {
	for (int i = 0; i < 20; i++) if (x & (1 << i)) a = r[a][i];
	return a;
}
int getlca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	b = upnode(b, dep[b] - dep[a]);
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (r[a][i] != r[b][i]) {
			a = r[a][i];
			b = r[b][i];
		}
	}
	return r[a][0];
}
int main() {
	int N, M, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	for (i = 0; i < 20; i++) r[1][i] = 1;
	DFS(1);

	scanf("%d", &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		printf("%d\n", getlca(t1, t2));
	}
	return 0;
}
//*/