import sys
#sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
troubles = set(sys.stdin.readline().strip().split())

def isPossible(target):
	return target >= 0 and len(set(str(target)) & troubles) == 0

def getNums():
	answer = len(str(n))

	for i in range(1000003):
		if n+i == 100 or n-i == 100: return i
		if isPossible(n+i): return min(len(str(n+i)), abs(n+i-100)) + i
		elif isPossible(n-i): return min(len(str(n-i)), abs(n-i-100)) + i

	return answer

def getPossible():
	rng = 500000*2-100-1
	nums = [False]*rng
	for i in range(rng):
		if len(set(str(i)) & troubles) == 0:
			nums[i] = True
	nums[100] = True
	answer = abs(n-100)
	for i in range(rng):
		if nums[i]:
			answer = min(len(str(i)) + abs(n-i), answer)
		# if n-i>=0 and nums[n-i]:
		# 	return min(len(str(n-i)), abs(n-i-100)) + i
		# elif n+i<1000002 and nums[n+i]:
		# 	return min(len(str(n+i)), abs(n+i-100)) + i

	return answer

print(getPossible())