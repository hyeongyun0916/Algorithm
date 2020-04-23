# python의 4사5입 round를 찾으려했지만 실패
# 어차피 정수이기 때문에 그냥 0.5 더해준 상태에서 round 처리해줌

a, b = list(map(int,input().split()))
print(int(round(a+0.5, -1*b)))