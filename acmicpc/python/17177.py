def getAnswer(a, b, c):
    if a == 0 or b*b-4*a*c<0:
        return -1
    
    return (-1*b+pow(b*b-4*a*c, 0.5))/(2*a)

a, b, c = list(map(int,input().split()))

alpha = a*a
beta = 2*a*b*c
gamma = b*b*c*c-(a*a-b*b)*(a*a-c*c)

answer = getAnswer(alpha, beta, gamma)

if answer > 0:
    print(int(answer))
else:
    gamma = b*b*a*a+c*c*a*a-a*a*a*a
    answer = getAnswer(alpha, beta, gamma)
    if answer > 0:
        print(int(answer))
    else:
        print(-1)
