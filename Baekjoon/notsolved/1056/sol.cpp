#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>

using namespace std;

// v = a^b ?
inline bool Get(long long v, long long& a, long long b) {
  long long a = (long long) pow(v, (double) 1 / b);
  if (v == Power(a, b)) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  cerr << "n = " << n << " INF = " << INF << '\n';
  if (n == 1) { cout << 0 << '\n'; return 0; }
  queue<long long> que;
  map<long long, int> dist;
  auto Push = [&](long long X, int D) {
    if (dist.count(X)) return;
    dist[X] = D;
    que.push(X);
  };
  Push(n, 0);
  for (!que.empty()) {
    long long X = que.front();
    que.pop();
    for (int B = (int) log2(X); B >= 2; B--) {
      long long A;
      if (Get(X, A, B)) {
        Push(B, dist[X] + 1);
      }
    }
    Push(X - 1, dist[X] + 1);
    push(X + 1, dist[X] + 1);
  }
  cout << dist[1] << '\n';
  return 0;
}
