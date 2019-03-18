#include <iostream>   
#include <ctime>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d, k;
  cin >> d >> k;
  int v[30] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040};
  /*v[0] = v[1] = 1;
  cerr << v[0] << ',' << v[1] << ',';
  for (int i = 2; i < 30; i++) {
    v[i] = v[i - 2] + v[i - 1];
    cerr << v[i] << ',';
  }*/
  int a, b = 1;
  for (a = 1; a < k / 2 + 1; a++) {
    if ((k - a * v[d - 3]) % v[d - 2] == 0) {
      b = (k - a * v[d - 3]) / v[d - 2];
      break;
    }    
  }  
  cout << a << '\n' << b << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
