#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int) 1e6;

bool com[N], chk[N];
vector<long long> prime;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long mn, mx;
  cin >> mn >> mx;
  for (long long i = 2; i < N; i++) {
    if (com[i]) continue;
    prime.push_back(i * i);
    for (long long j = 2 * i; j < N; j += i) {
      com[j] = true;
    }
  }
  int ans = 0;
  int n = (int) prime.size();
  for (int i = 0; i < n; i++) {
    for (long long j = ceil((double) mn / prime[i]) * prime[i]; j <= mx; j += prime[i]) {
      chk[j - mn] = true;
    }
  } 
  for (long long i = mn; i <= mx; i++) {
    if (!chk[i - mn]) ans++;
  }
  cout << ans << '\n';
//cerr << (float) clock() / CLOCKS_PER_SEC << " seconds " << '\n';
  return 0;
}