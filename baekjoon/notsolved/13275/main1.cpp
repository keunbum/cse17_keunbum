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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char u[100050];
char in[200050];

int dp[200050];
int main() {
	scanf("%s", u);
	int L = strlen(u), i, j;

	for (i = 0; i < L; i++) {
		in[2 * i] = u[i];
		if (i + 1 != L) in[2 * i + 1] = '#';
	}

	dp[0] = 0;
	int mx = 0;
	for (i = 1; i <= 2 * L - 2; i++) {
		int p = mx + dp[mx];
		if (i <= p) dp[i] = min(p - i, dp[2*mx-i]);

		while (dp[i] < i) {
			if (in[i - dp[i] - 1] == in[i + dp[i] + 1]) dp[i]++;
			else break;
		}
		if (i + dp[i] > p) mx = i;
	}

	int ans = 0;
	for (i = 0; i <= 2 * L - 2; i++) {
		if (i % 2 == 0) ans = max(ans, (dp[i]/2) * 2 + 1);
		else ans = max(ans, (dp[i] + 1) / 2 * 2);
	}
	return !printf("%d\n", ans);
}
