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
const int MOD = 987654321;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

vector <pli> V;
char in[100];
int main() {
	scanf("%s", in);
	for (int i = 0; in[i] != 0; i++) {
		if (in[i] >= '0' && in[i] <= '9') {
			if (!V.empty() && V.back().first > 0) {
				V.back().first++;
				V.back().second = in[i] - '0';
			}
			else V.push_back(pli(1, in[i] - '0'));
		}
		else if (in[i] == '(') V.push_back(pli(-1, -1));
		else {
			if (V.back().first < 0) {
				V.pop_back();
				V.back().first--;
				if (V.back().first == 0) V.pop_back();
			}
			else {
				pli t = V.back();
				V.pop_back();
				V.pop_back();
				V.back().first = V.back().first - 1 + V.back().second * t.first;
				V.back().second = t.second;
				if (V.back().first == 0) V.pop_back();
			}
		}
	}
	if (V.empty()) printf("0");
	else printf("%lld", V.back().first);
	return 0;
}
