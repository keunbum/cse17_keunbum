#include <bits/stdc++.h>

using namespace std;

class BInt {
public:
  const static int LEN = 9;
  const static int ONE_DIGIT = (int) 1e9;
  vector<int> a;
  BInt() {
    *this = BInt("");
  }
  BInt(string s) {
    int n = (int) s.size();
    for (int i = n - 1; i >= 0; i -= LEN) {
      int foo = 0;
      int e = 1;
      for (int j = 0; i - j >= 0 && j < LEN; j++, e *= 10) {
        foo += (s[i - j] - '0') * e;
      }
      push(foo);
    }
  }
  void push(int n) {
    a.push_back(n);
  }
  void modify(int& carry) {
    int &e = a.back();
    if (e >= ONE_DIGIT) {
      carry = 1;
      e -= ONE_DIGIT;
    } else {
      carry = 0;
    }
  }
  BInt operator+(const BInt& y) {
    const BInt& x = *this;
    int n = (int) x.a.size();
    int m = (int) y.a.size();
    BInt z("");
    int carry = 0;
    int i;
    for (i = 0; i < min(n, m); i++) {
      z.push(x.a[i] + y.a[i] + carry);
      z.modify(carry);
    }
    const BInt& o = (n > m ? x : y);
    for ( ; i < max(n, m); i++) {
      z.push(o.a[i] + carry);
      z.modify(carry);
    }
    if (carry == 1) {
      z.push(1);
    }
    return z;
  }
  friend std::istream& operator>>(std::istream& stream, BInt& bint);
};

string to_string(const BInt& b) {
  string res = "";
  int n = b.a.size();
  for (int i = n - 1; i >= 0; i--) {
    string foo = to_string(b.a[i]);
    int m = (int) foo.size();
    string bar(b.LEN - m, '0');
    if (i < n - 1) {
      res += bar;
    }
    res += foo;
  }
  return res;
}

std::ostream& operator<<(std::ostream& stream, const BInt& number) {
  return stream << to_string(number);
}

std::istream& operator>>(std::istream& stream, BInt& number) {
  string s;
  stream >> s;
  number = BInt(s);
  return stream;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  BInt a, b;
  cin >> a >> b;
  BInt c = a + b;
  cout << c << '\n';
  return 0;
}
