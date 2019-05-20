#include <iostream>
#include <algorithm>

using namespace std;

static char _buffer[1024];
static int _currentChar = 0;
static int _charsNumber = 0;

static inline int _read() {
  if (_charsNumber < 0) {
    exit(1);
  }
  if (!_charsNumber || _currentChar == _charsNumber) {
    _charsNumber = (int) fread(
  }
}

int main() {
  int n = _readInt();
  int k = _readInt();
  int a[(int) 5000000];
  for (int i = 0; i < n; i++) {
    a[i] = _readInt();
  }
  sort(a, a + n);
  cout << a[k-1] << '\n';
  return 0;
}
