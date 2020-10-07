cowMap = {}
num = int(input())
count = 0
for i in range(num):
	cow = input().split()
	if cow[0] in cowMap:
		if cowMap[cow[0]] != cow[1]:
			count += 1
	cowMap[cow[0]] = cow[1]
print(count)