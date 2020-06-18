import sys

# sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))

answer = [1]*len(arr)

for i in range(len(arr)):
    for j in range(i):
        if arr[j] < arr[i]:
            answer[i] = max(answer[i],answer[j]+1)

print(max(answer))