//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
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
const int MOD = 1000000000;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

int fact[10];
int dis[400000];
int Q[400000];
int rev[400000];
bool Q_chk[400000];

int array_to_num(int *k, int N){
	int rv = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = i + 1; j < N; j++) if (k[i] > k[j]) cnt++;
		rv += cnt*fact[N - 1 - i];
	}
	return rv;
}

int* num_to_array(int x, int N) {
	bool chk[10];
	int* k = new int[N];
	for (int i = 0; i < N; i++) chk[i] = false;
	for (int i = 0; i < N; i++) {
		int t = x / fact[N - 1 - i];
		x = x%fact[N - 1 - i];
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (chk[j]) continue;
			if (cnt == t) {
				k[i] = j;
				chk[j] = true;
				break;
			}
			cnt++;
		}
	}
	return k;
}

int P[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
int main() {
	int i, j, k;
	fact[0] = 1;
	for (i = 1; i < 9; i++) fact[i] = fact[i - 1] * i;
	int* in = new int[9];
	for (i = 0; i < 9; i++) scanf("%d", &in[i]);

	int S = array_to_num(in, 9);
	for (i = 0; i < 9; i++) in[i] = (i + 1) % 9;
	int E = array_to_num(in, 9);

	int st = 1, en = 2;
	Q[1] = S;
	dis[S] = 0;
	Q_chk[S] = true;
	while (st < en) {
		int* t = new int[9];
		t = num_to_array(Q[st], 9);
		int* t2 = new int[9];
		for (i = 0; i < 9; i++) t2[i] = t[i];
		int x1, x2, x;
		for (i = 0; i < 9; i++) {
			if (t[i] == 0) {
				x = i;
				x1 = i / 3;
				x2 = i % 3;
			}
		}

		for (i = 0; i < 4; i++) {
			int y1 = x1 + P[i][0];
			int y2 = x2 + P[i][1];
			int y = 3 * y1 + y2;
			if (y1 < 0 || y1 >= 3 || y2 < 0 || y2 >= 3) continue;
			swap(t2[x], t2[y]);
			int z = array_to_num(t2, 9);
			swap(t2[x], t2[y]);
			if (Q_chk[z]) continue;
			Q[en++] = z;
			Q_chk[z] = true;
			dis[z] = dis[Q[st]] + 1;
			rev[z] = Q[st];
		}
		st++;
		free(t);
		free(t2);
	}
	if (!Q_chk[E]) {
		printf("-1\n");
		return 0;
	}
	printf("%d", dis[E]);
	/*while (E != S) {
		int* t = new int[9];
		t = num_to_array(E, 9);
		for (i = 0; i < 9; i++) printf("%d ", t[i]);
		printf("\n");
		E = rev[E];
	}*/
	return 0;
}
//*/
