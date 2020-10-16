n = int(input())
nums = [int(x) for x in input().split()]
str = input()
strDict = dict()
for ch in str:
#	print(ch)
	ch = ord(ch)
	if ch is ord(' '):
		ch = 0
	elif ch < ord('a'):
		ch = ch - ord('A') + 1
	else:
		ch = ch - ord('a') + 27
#	print(ch)
	strDict[ch] = strDict.get(ch, 0) +1

# print(strDict)	

isPossible = True
for num in nums:
	strDict[num] = strDict.get(num, 0) -1
	# print(num, strDict[num])

for key in strDict:
	if not strDict[key] is 0:
		isPossible = False

# print(strDict)
print('y') if isPossible else print('n')
