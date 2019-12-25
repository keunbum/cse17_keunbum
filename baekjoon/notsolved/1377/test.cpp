#include <iostream>
#include <ctime>

using namespace std;

int main() {
  srand(time(0));
  int n = 500000;
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    cout << rand() % ((int) 1e6 + 1) << '\n';
  }
  return 0;
}