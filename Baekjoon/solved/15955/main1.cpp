#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

pii in[300050];

int u[300050];

vector <pair<int, pii>> Vu;

vector <pii> conn[300050];

int r[300050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

bool dchk[300050];
int par[300050][20][2];
int dep[300050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		int d = it.first, nn = it.second;
		if (dchk[nn]) continue;
		par[nn][0][0] = n;
		par[nn][0][1] = d;
		dep[nn] = dep[n] + 1;
		for (int i = 1; i < 19; i++) {
			int tp = par[nn][i - 1][0];
			par[nn][i][0] = par[tp][i - 1][0];
			par[nn][i][1] = max(par[nn][i - 1][1], par[tp][i - 1][1]);
		}
		DFS(nn);
	}
}

int getdis(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	int c = dep[b] - dep[a];

	int rv = 0;
	for (int i = 19; i >= 0; i--) {
		if (c & (1 << i)) {
			rv = max(rv, par[b][i][1]);
			b = par[b][i][0];
		}
	}
	if (a == b) return rv;
	
	for (int i = 19; i >= 0; i--) {
		if (par[a][i][0] != par[b][i][0]) {
			rv = max(rv, par[a][i][1]);
			rv = max(rv, par[b][i][1]);
			a = par[a][i][0];
			b = par[b][i][0];
		}
	}
	rv = max(rv, par[a][0][1]);
	rv = max(rv, par[b][0][1]);
	return rv;
}

int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i].first, &in[i].second);
	
	for (i = 1; i <= N; i++) u[i] = i;
	
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a] < in[b];
	});
	for (i = 1; i < N; i++) {
		int t1 = u[i], t2 = u[i + 1], d = in[t2].first - in[t1].first;
		Vu.emplace_back(d, pii(t1, t2));
	}

	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a].second < in[b].second;
	});
	for (i = 1; i < N; i++) {
		int t1 = u[i], t2 = u[i + 1], d = in[t2].second - in[t1].second;
		Vu.emplace_back(d, pii(t1, t2));
	}
	
	sort(all(Vu));
	for (i = 1; i <= N; i++) r[i] = i;
	for (auto it : Vu) {
		int d = it.first, t1 = it.second.first, t2 = it.second.second;
		if (root(t1) == root(t2)) continue;

		conn[t1].emplace_back(d, t2);
		conn[t2].emplace_back(d, t1);
		r[root(t1)] = root(t2);
	}

	for (i = 0; i < 20; i++) par[1][i][0] = 1;
	DFS(1);

	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (getdis(t1, t2) <= t3) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}