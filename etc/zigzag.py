def getMark(n):
    if n > 0:
        return 1
    elif n == 0:
        return 0
    else:
        return -1

def isPossible(arr):
    if len(arr) < 3:
        return 1
    for i in range(0, len(arr)-2):
        if arr[i] == arr[i+1]:
            return 0
        if getMark(arr[i]-arr[i+1])*-1 != getMark(arr[i+1]-arr[i+2]):
            return 0
    return 1

def solution(arr):
    stranges = []
    for i in range(len(arr)-2):
        if arr[i] == arr[i+1]:
            stranges.append(i+1)
            continue
        if getMark(arr[i]-arr[i+1])*-1 != getMark(arr[i+1]-arr[i+2]):
            stranges.append(i+1)

    if len(stranges) == 0:
        return 0

    if len(stranges) == 2:
        if stranges[0]+1 != stranges[1]:
            return -1
    
    if len(stranges) > 2:
        return -1

    answer = 0

    newArr = arr[max(stranges[0]-2,0):min(stranges[-1]+3, len(arr))]
    
    for i in range(len(newArr)):
        answer += isPossible(newArr[:i]+newArr[i+1:])

    return -1 if answer == 0 else answer


print(solution([3,4,5,3,7]))
print(solution([3,4,4,3]))
print(solution([3,3,3,4,3]))
print(solution([5,3,6,2,1]))
print(solution([4,5,3,7,8]))