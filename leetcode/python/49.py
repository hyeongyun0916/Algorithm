import sys
sys.stdin = open('input.txt', 'r')
strs = sys.stdin.readline().strip().split()

counts = [[0 for _ in range(26)] for _ in range(len(strs))]
a_ord = ord('a')
d = dict()
for i in range(len(strs)):
    for s in strs[i]:
        counts[i][ord(s)-a_ord] += 1

for i in range(len(counts)):
    k = ''.join(map(str, counts[i]))
    if k in d:
        d[k].append(strs[i])
    else:
        d[k] = [strs[i]]

answer = []
for k in d:
    answer.append(d[k])

answer.sort()

print(answer)
