#include <iostream>
#include <functional>

using namespace std;

int main() {
	function<int(int)> F = [&](int x) {
		if (x == 1) {
			return 1;
		}
		return F(x - 1) * x;
	};
	int n;
	cin >> n;
	cout << F(n) << '\n';
	return 0;
}
