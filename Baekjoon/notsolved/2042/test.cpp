#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);  
  cin.tie(0);
  const int N = 10000;
  for (int i = 0; i <= N; i++) {
    cout << i << ": ";
    cout << 
    cout << (i & (-i)) << '\n';
  }
  return 0;
}