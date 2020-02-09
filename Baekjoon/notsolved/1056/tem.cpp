#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long lld;
 
class ThePower {
  public:
  lld f(lld val, lld n)
  {
    lld p = val;
    lld last = val;
    while(val <= n)
    {
      last = val;
      val *= p;
    }
    
    lld r1 = p;
    lld r2 = p;
    
    r1 += (val - n);
    r2 += (n - last);
    
    return min(r1, r2);
  }
  int count(long long n) {
    if(n == 1) return 0;
    
    lld l = 2;
    lld r = (lld)sqrt(n) + 10;
    lld best = -1;
    
    cout << f(4, n) << endl;
    
    while(l < r - 3)
    {
      lld mid = (l + r) / 2;
      lld mid2 = mid + 1;
      cout << mid << " " << mid2 << " " << f(mid,n) << " " << f(mid2,n) << endl;
      lld f1 = f(mid, n);
      lld f2 = f(mid2, n);
      
      if(best == -1) best = f1;
      else best = min(best, min(f1, f2));
      
      if(f1 <= f2)
      {
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    
    for(lld i = l; i <= r; i++) { best = min(best, f(i, n)); cout << f(i,n) << " " << i << endl; }
    
    return (int)best;
  }
};
 
// Powered by PopsEdit