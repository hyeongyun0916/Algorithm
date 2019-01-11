num = int(input())
arr = []
for i in range(num):
	inst = input().split()
	if inst[0] == 'push_front':
		arr.insert(0, inst[1])
	elif inst[0] == 'push_back':
		arr.append(inst[1])
	elif inst[0] == 'pop_front':
		if len(arr):
			print(arr[0])
			del arr[0]
		else:
			print(-1)
	elif inst[0] == 'pop_back':
		if len(arr):
			print(arr.pop())
		else:
			print(-1)
	elif inst[0] == 'size':
		print(len(arr))
	elif inst[0] == 'empty':
		print(0) if len(arr) else print(1)
	elif inst[0] == 'front':
		if len(arr):
			print(arr[0])
		else:
			print(-1)
	elif inst[0] == 'back':
		if len(arr):
			print(arr[len(arr) -1])
		else:
			print(-1)
	else:
		print(inst[0])