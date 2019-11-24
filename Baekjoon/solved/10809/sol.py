s = input().rstrip('\n')
a = [-1 for i in range(26)]
for i in range(len(s) - 1, -1, -1):
	a[ord(s[i]) - ord('a')] = i
print(*a)
