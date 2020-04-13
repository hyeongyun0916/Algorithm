# 2275 부녀회장

num = int(input())
max_k = 0
max_n = 0
kn = list()
for i in range(num):
    k = int(input())
    n = int(input())
    kn.append([k, n])
    max_k = max(max_k, k)
    max_n = max(max_n, n)

answer = list()

sub_list = list()
for i in range(max_n):
    sub_list.append(i+1)
answer.append(sub_list)
for i in range(1, max_k+1):
    sub_list = list()
    sub_list.append(1)
    for j in range(1, max_n):
        sub_list.append(sub_list[len(sub_list)-1]+answer[i-1][j])
    answer.append(sub_list)

for i in range(num):
    print(answer[kn[i][0]][kn[i][1]-1])