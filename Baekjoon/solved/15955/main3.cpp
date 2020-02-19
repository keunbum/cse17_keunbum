#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 250005

typedef long long lint;
typedef pair<lint, int> pli;

lint X[MAXN], Y[MAXN];
int A[MAXN], B[MAXN], C[MAXN];
int xs[MAXN], ys[MAXN];
pli edges[2*MAXN];
vector<pli> ed[MAXN];
int uni[MAXN];
pli par[20][MAXN];
int dep[MAXN];

int guni(int x){
	if(x == uni[x]) return x;
	return uni[x] = guni(uni[x]);
}

void dfs(int x) {
	for(auto a : ed[x]) if(par[0][a.second].second == 0) {
		par[0][a.second] = make_pair(a.first, x);
		dep[a.second] = dep[x] + 1;
		dfs(a.second);
	}
}

lint lcad(int x, int y) {
	lint ans = 0ll;

	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) if(dep[x] >= dep[y] + (1ll << i)) {
		ans = max(ans, par[i][x].first);
		x = par[i][x].second;
	}
	if(x == y) return ans;
	for(int i = 19; i >= 0; i--) if(par[i][x].second != par[i][y].second) {
		ans = max(ans, max(par[i][x].first, par[i][y].first));
		x = par[i][x].second;
		y = par[i][y].second;
	}
	return max(ans, max(par[0][x].first, par[0][y].first));
}

int main() {
	int N, Q;

	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%lld%lld", X+i, Y+i);
	for(int i = 0; i < Q; i++) scanf("%d%d%d", A+i, B+i, C+i);

	for(int i = 0; i < N; i++) xs[i] = ys[i] = i + 1;
	sort(xs, xs+N, [&](const int a, const int b) { return X[a] < X[b]; } );
	sort(ys, ys+N, [&](const int a, const int b) { return Y[a] < Y[b]; } );

	//for(int i = 0; i < N; i++) printf("%d %d\n", xs[i], ys[i]);

	for(int i = 1; i <= N; i++) uni[i] = i;
	for(int i = 0; i < N-1; i++) {
		edges[i*2] = make_pair(X[xs[i+1]] - X[xs[i]], i);
		edges[i*2+1] = make_pair(Y[ys[i+1]] - Y[ys[i]], i+N);
	}
	sort(edges, edges + 2*N-2);
	for(int i = 0; i < 2*N-2; i++) {
		pli t = edges[i];
		int a, b;
		if(t.second < N) {
			a = xs[t.second];
			b = xs[t.second + 1];
		}
		else {
			a = ys[t.second - N];
			b = ys[t.second - N + 1];
		}
		if(guni(a) != guni(b)) {
			uni[guni(a)] = guni(b);
			ed[a].push_back(make_pair(t.first, b));
			ed[b].push_back(make_pair(t.first, a));
		}
	}
	
	par[0][1] = make_pair(0ll, 1);
	dfs(1);
	for(int i = 1; i < 20; i++) for(int j = 1; j <= N; j++)
		par[i][j] = make_pair(max(par[i-1][par[i-1][j].second].first, par[i-1][j].first), par[i-1][par[i-1][j].second].second);

	//for(int i = 1; i <= N; i++) printf("(%lld, %d)", par[0][i].first, par[0][i].second);

	for(int i = 0; i < Q; i++) {
		if(lcad(A[i], B[i]) <= C[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
