ans = 0
def IsHan(n):
	if n < 100:
		return True
	a = n // 100
	b = (n // 10) % 10
	c = n % 10
	return b + b == a + c
for i in range(1, int(input()) + 1):
	ans += int(IsHan(i))
print(ans)
