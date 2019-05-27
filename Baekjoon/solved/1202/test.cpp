#include <iostream>
#include <ctime>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(0));
  int n = (int) 3e2;
  int k = (int) 3e2;
  cout << n << ' ' << k << '\n';
  int M = (int) 1e6, V = (int) 1e6, C = (int) 1e6;
  for (int i = 0; i < n; i++) {
    cout << rand() % M << ' ' << rand() % V << '\n';
  }
  for (int i = 0; i < k; i++) {
    cout << rand() % C << '\n';
  }
  return 0;
}

