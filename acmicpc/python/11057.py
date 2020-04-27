n = int(input())
dp = []
dp.append([1 for _ in range(10)])
for i in range(n -1):
	tempList = [1]
	for j in range(9):
		tempList.append((tempList[j]+dp[i][j+1])%10007)
	dp.append(tempList)

answer = 0

print(sum(dp.pop())%10007)
