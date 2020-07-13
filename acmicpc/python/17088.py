import copy
n = int(input())
bs = list(map(int,input().split()))

v = [-1, 0, 1]

answer = 987654321

if n == 0 or n == 1:
	print(0)
	exit(0)


for i in v:
	start = bs[0]+v[i]
	for j in v:
		end = bs[n-1]+v[j]
		step = (start-end)/(n-1)
		if not (step == int(step)):
			continue
		else:
			# print(start, end, step)
			tempBs = copy.deepcopy(bs)
			tempBs[0] = start
			tempAnswer = 0 if start == bs[0] else 1
			isSequence = True
			for index in range(1, n):
				if tempBs[index] == tempBs[index-1] -step:
					continue
				elif tempBs[index] -1 == tempBs[index-1] -step:
					tempBs[index] -= 1
					tempAnswer += 1
				elif tempBs[index] +1 == tempBs[index-1] -step:
					tempBs[index] += 1
					tempAnswer += 1
				else:
					isSequence = False
					break
				# print(tempBs)
			if isSequence:
				answer = answer if answer < tempAnswer else tempAnswer

answer = -1 if answer == 987654321 else answer
print(answer)