while True:
	tri = [int(x) for x in input().split()]
	if tri[0] == 0:
		break
	tri.sort()
	if tri[0] + tri[1] <= tri[2]:
		print('Invalid')
	elif tri[0] == tri[1] == tri[2]:
		print('Equilateral')
	elif tri[0] == tri[1] or tri[1] == tri[2]:
		print('Isosceles')
	else:
		print('Scalene')