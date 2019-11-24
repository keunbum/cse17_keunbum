import sys

a = [0] * 42;
for i in range(10):
	n = int(sys.stdin.readline())
	a[n % 42] = 1;
print(sum(a))
