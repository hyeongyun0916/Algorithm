n, c, r = [int(i) for i in input().split()]
two = set()
for i in range(n):
  two.add(1<<i)
# print(two)
n = 1 << n
# print(n,c,r)
dx = [0, 2, 6, 2]
dy = [0, 1, 3, 1]

temp = 4
for i in range(4,n):
  if i in two:
    dx.append((i*i*2)-sum(dx[:i]))
    temp = i
  else:
    dx.append(dx[i-temp])
# print(dx)
for i in range(4,n):
  if i in two:
    dy.append((i*i)-sum(dy[:i]))
    temp = i
  else:
    dy.append(dy[i-temp])
# print(dy)
print(sum(dx[:c+1])+sum(dy[:r+1]))