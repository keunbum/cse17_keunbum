def D(n):
	res = n
	while (n > 0):
		res += n % 10
		n //= 10
	return res
MAX = int(1e4)
s = set()
for i in range(1, MAX + 1):
	if i not in s:
		print(i)
	s.add(D(i))
