ans = 0
for tt in range(int(input())):
	s = input()
	chk = [False for i in range(128)]
	ok = True
	for i in range(len(s)):
		if chk[ord(s[i])] and s[i - 1] != s[i]:
			ok = False
			break
		chk[ord(s[i])] = True
	ans += int(ok)
print(ans)
