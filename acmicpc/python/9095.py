t = int(input())
nums = [1,2,4]
value = 1+2+4
for i in range(4, 12):
	nums.append(value)
	# print(value)
	value = value*2 - nums[i-4]

for i in range(t):
	n = int(input())
	print(nums[n-1])
	
