#include <iostream>

using namespace std;

const int md = (int) 1e3;

struct Matrix {
  int n;
  int a[5][5];
  Matrix() {
    Matrix(0);
  }
  Matrix(int n) : n(n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
      a[i][i] = 1;
    }
  }
  Matrix& operator*=(const Matrix& other) {
    Matrix was(*this);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int k = 0; k < n; k++) {
          sum += was.a[i][k] * other.a[k][j];
        }
        a[i][j] = sum % md;
      }
    }
    return *this;
  }
  void print() const {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j];
        cout << (j == n - 1 ? '\n' : ' ');
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long b;
  cin >> n >> b;
  Matrix a(n), ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a.a[i][j];
    }
  }
  while (b) {
    if (b & 1) {
      ans *= a;
    }
    a *= Matrix(a);
    b >>= 1;
  }
  ans.print();
  return 0;
}