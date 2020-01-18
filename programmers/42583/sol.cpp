#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4;

int q[N];

int solution(int len, int w, vector<int> a) {
  int n = (int) a.size();
  int sum = 0;
  int passed = 0;
  int time = 0;
  int i = 0;
  int b = 0, e = 0;
  while (passed < n) {
    if (b < e && time - q[b] == len) {
      sum -= a[passed];
      passed++;
      ++b;
    }
    if (i < n && sum + a[i] <= w) {
      sum += a[i];
      i++;
      q[e] = time;
      ++e;
    }
    time++;
  }
  return time;
}
