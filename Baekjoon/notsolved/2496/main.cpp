#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int in[105][2];
int N, K;
int mx = -1, x = -1, y = -1;
void getans(int a, int b) {
	int c = 0;
	for (int i = 1; i <= N; i++) {
		if (in[i][0] + in[i][1] < a) continue;
		if (in[i][0] + in[i][1] > a + K) continue;
		if (in[i][0] - in[i][1] < b) continue;
		if (in[i][0] - in[i][1] > b + K) continue;
		c++;
	}
	if (c > mx) {
		mx = c;
		x = (a + b) / 2;
		y = (a - b) / 2;
	}
}

int main() {
	int t1, t2, i, j, k;
	scanf("%d %d %d %d", &t1, &t2, &N, &K);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			int a = in[i][0] + in[i][1], b = in[j][0] - in[j][1];
			if ((a + b) % 2) {
				getans(a, b - 1);
				getans(a, b + 1);
			}
			else getans(a, b);
		}
	}
	printf("%d %d\n", x+K/2, y);
	printf("%d\n", mx);
	return 0;
}
//*/