//*
#include <algorithm>
#include <iostream>
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

const int IT_MAX = 524288;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

int in[10];
bool chk[10];
int pos[10];
int ans = 0;
void aa(int lvl, int N) {
  if (lvl == N) {
    int rv = 0;
    for (int i = 1; i < N; i++) rv += abs(in[pos[i]] - in[pos[i - 1]]);
    ans = max(ans, rv);
  //    for (int i = 0; i < N; i++) printf("%d ", in[pos[i]]);
  //    printf("\n");
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (chk[i]) continue;
    pos[lvl] = i;
    chk[i] = true;
    aa(lvl + 1, N);
    chk[i] = false;
  }
  return;
}
int main() {
  int N, i;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &in[i]);
  aa(0, N);
  printf("%d", ans);
  return 0;
}
//*/