import sys
# sys.stdin = open('input.txt', 'r')

# https://www.acmicpc.net/problem/17178

isPosible = False

def isSmall(a, b):
    return (a[0] < b[0]) or (a[0] == b[0] and int(a[1]) < int(b[1]))

def go(lastTicket, waitPlace, tickets):
    global isPosible
    if (len(tickets) == 1):
        isPosible = isSmall(lastTicket, tickets[0]) and (len(waitPlace) == 0 or isSmall(lastTicket, waitPlace[-1]))
        return
    
    while len(waitPlace) > 0 and isSmall(waitPlace[-1], tickets[0]):
        if isSmall(lastTicket, waitPlace[-1]):
            lastTicket = waitPlace.pop(-1)
        else:
            return

    if isSmall(tickets[0], tickets[1]):
        if isSmall(lastTicket, tickets[0]):
            go(tickets[0], waitPlace, tickets[1:])
    else:
        go(lastTicket, waitPlace+[tickets[0]], tickets[1:])


n = int(input())

lastTicket = ['@','0']
waitPlace = []
tickets = []

for i in range(n):
    temps = [temp.split('-') for temp in sys.stdin.readline().strip().split()]
    tickets.extend(temps)

go(lastTicket, waitPlace, tickets)
print('GOOD' if isPosible else 'BAD')