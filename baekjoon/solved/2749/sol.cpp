#include <iostream>

using namespace std;

const int md = (int) 1e6;

struct Matrix {
  long long a[2][2];

  Matrix() {
    *this = Matrix(1, 0, 0, 1);
  }
  Matrix(int x, int y, int z, int r) {
    a[0][0] = x, a[0][1] = y;
    a[1][0] = z, a[1][1] = r;
  }
  Matrix& operator*=(const Matrix &other) {
    Matrix was(*this);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        long long s = 0;
        for (int k = 0; k < 2; k++) {
          s += was.a[i][k] * other.a[k][j];
        }
        (*this).a[i][j] = s % md;
      }
    }
    return (*this);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  Matrix ans, a(1, 1, 1, 0);
  while (n) {
    if (n & 1) { ans *= a; }
    a *= Matrix(a);
    n >>= 1;
  }
  cout << ans.a[0][1] << '\n';
  return 0;
}