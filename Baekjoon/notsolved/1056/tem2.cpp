#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include "time.h"
using namespace std;
#define SZ(x) (int)x.size()
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(i,t) for(i=t.begin();i!=t.end();++i)
typedef vector<int> VI;
typedef vector<string> VS;
#define prt if(1)printf
typedef long long i64;
#define POW(x,y) pow((double)x,(double)y)
 
double T;
double B;
i64 oo=1000000000000000500LL;
 
double calc(double val) {
  if (POW(B,val) > 10e18) {
    return oo;
  }
  return POW(B,val);
}
 
double binsearch() {  
  double lo = 0; // adjust lo and hi accordingly
  double hi = 1000000000; 
  double mid = (hi+1)/2;
  int cnt = 0;
  while ( fabs(hi-lo) >= 1e-12 && ++cnt <= 20000 ){
    mid = (lo+hi) / 2;
    double c = calc(mid);
    if (c < T) lo = mid;
    else hi = mid;
  }
  return (i64)floor(hi + 0.5);
}
 
 
struct ThePower {
  int count(long long n) { REP(i,1)prt("%s","");
  n=80; /////////////////////////
    if (n==1) return 0;
 
    T=n;
    int best = n;
    int c;
    for(long long i = 2; i < 5; ++i) {
      B=i;
      c = binsearch();
      i64 xx = POW(i,c);
      i64 diff = fabs(xx-T) + 2;
      if (diff < best) {
        best = diff;
      }
    }
 
    return best;
  }
};
 
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
