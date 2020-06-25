import sys
# sys.stdin = open('input.txt', 'r')

n, m = map(int, sys.stdin.readline().strip().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().strip().split())))

sumArr = [[0]*(n+1)]
for x in range(n):
    tempArr = [0]
    for y in range(n):
        tempArr.append(arr[x][y]+tempArr[y]+sumArr[x][y+1]-sumArr[x][y])
    sumArr.append(tempArr)

for _ in range(m):
    a, b, c, d = map(int, sys.stdin.readline().strip().split())
    print(sumArr[c][d]-sumArr[a-1][d]-sumArr[c][b-1]+sumArr[a-1][b-1])

# print(sumArr)