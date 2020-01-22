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

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

int it[IT_MAX+50];

void update(int pos, int val) {
	while (pos <= IT_MAX) {
		it[pos] += val;
		pos += pos&(-pos);
	}
}

int getsum(int pos) {
	int rv = 0;
	while (pos > 0) {
		rv += it[pos];
		pos -= pos&(-pos);
	}
	return rv;
}
int main() {
	int N, i, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		update(t + 10001, 1);
		int p = (i + 1) / 2;
		int st = 1, en = 20001, mi, ans = 0;
		while (st <= en) {
			mi = (st + en) / 2;
			if (getsum(mi) >= p) {
				ans = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		printf("%d\n", ans - 10001);
	}
	return 0;
}
//*/

