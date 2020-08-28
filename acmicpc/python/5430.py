import sys
# sys.stdin = open('input.txt', 'r')

t = int(sys.stdin.readline())

for _ in range(t):
	cmd = sys.stdin.readline().strip()
	n = int(sys.stdin.readline())
	arr = sys.stdin.readline().strip()
	arr = arr.replace('[','').replace(']','').split(',')
	if arr == ['']: del arr[0]
	isError = False
	isReverse = 0
	for ch in cmd:
		if ch == 'R':
			isReverse ^= 1
		else:
			if len(arr) == 0:
				isError = True
				break
			else:
				if isReverse == 1: del arr[len(arr)-1]
				else: del arr[0]
	if isError:
		print('error')
	else:
		if isReverse == 1: arr.reverse()
		print('[',','.join(arr),']',sep='')