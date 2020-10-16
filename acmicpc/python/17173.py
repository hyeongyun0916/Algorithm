n, m = [int(x) for x in input().split()]
nums = [int(x) for x in input().split()]

answer = 0
for i in range(n+1):
	for j in nums:
		if i % j is 0:
			# print(i)		
			answer += i
			break
			
print(answer)