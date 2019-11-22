a=[]
for i in range(5):
	if input().find('FBI') != -1:
		a.append(-~i)
if len(a) > 0:
	print(*a)
else:
	print('HE GOT AWAY!')
