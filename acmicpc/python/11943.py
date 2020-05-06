ab = [int(x) for x in input().split()]
cd = [int(x) for x in input().split()]
print(min(ab[0]+cd[1], ab[1]+cd[0]))