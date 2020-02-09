#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class FairSplit {
public:
  long long count(int, int, int, int);
};
 
pair<long long, long long> Count(long long R) {
  R += 1;
  long long x = R / 2;
  long long y = R / 2;
  if (R % 2 == 1) {
    if (((R - 1) * R / 2) % 2 == 0) {
      ++x;
    } else {
      ++y;
    }
  }
  return make_pair(x, y);
}
 
pair<long long, long long> Count4(long long L, long long R) {
  auto x = Count(R);
  auto y = Count(L - 1);
  return make_pair(x.first - y.first, x.second - y.second);
}
 
long long Count2(long long R, long long p) {
  R += 1;
  long long x = R / 2;
  if (R % 2 == 1 && p == 0) {
    x += 1;
  }
  return x;
}
 
long long Count2(long long L, long long R, long long p) {
  return Count2(R, p) - Count2(L - 1, p);
}
 
long long Solve(long long A, long long B) {
  if (A > B) {
    A = B;
  }
  if (A < 1 || B < 1) {
    return 0;
  }
  long long cnt = A * A / 4;
  if (A < B) {
    auto x = Count4(0, A - 1);
    auto y = Count4(A + 1, B);
    cnt += x.first * y.first + x.second * y.second;
  }
  for (long long h = 0; h * h < A; h++) {
    long long from = h * h + 1;
    long long to = min(A, B - 2 * h);
    if (from > to) {
      continue;
    }
    cnt -= Count2(from, to, h % 2);
  }
  return cnt;
}
 
long long FairSplit::count(int loA, int hiA, int loB, int hiB) {
  return Solve(hiA, hiB) - Solve(loA - 1, hiB) - Solve(hiA, loB - 1) + Solve(loA - 1, loB - 1);
}
 
 
//Powered by [KawigiEdit] 2.0!