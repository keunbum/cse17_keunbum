a = []
for i in range(5):
	if 'FBI' in input():
		a.append(-~i)
if (len(a) == 0):
	print('HE GOT AWAY!')
else:
	print(*a)
