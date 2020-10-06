first = list(map(int,input().split()))
second = list(map(int,input().split()))
third = list(map(int,input().split()))


first.sort(reverse=True)
second.sort(reverse=True)
third.sort(reverse=True)

sortedArr = [first, second, third]

# print(sortedArr)
sortedArr.sort(reverse=True)
# print(sortedArr)

a,b,c,d,e,f = sortedArr[0][0], sortedArr[0][1], sortedArr[1][0], sortedArr[1][1], sortedArr[2][0], sortedArr[2][1]

# print(a,b,c,d,e,f)


flag = False
if a-b==c:
	if a-b==f:
		if a==d+e:
			flag = True
	if a-b==e:
		if a==d+f:
			flag = True
elif a-b==d:
	if a-b==f:
		if a==c+e:
			flag = True
	if a-b==e:
		if a==c+f:
			flag = True
elif a == c == e == b+d+f:
    flag = True
    
if flag:
	print("YES")
else:
	print("NO")


		
	
		
	

		
	
		
		
	
		
	


