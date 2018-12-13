arr = []
n = int(input())
for i in range(n):
    temp = int(input())
    arr.append(temp)
arr.sort()
for i in range(n):
    print(arr[i])