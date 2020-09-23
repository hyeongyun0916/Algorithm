from itertools import combinations 

def divide(weak, dist):
    print(weak)
    combs = combinations(range(len(weak)-1), len(dist)-1)
    for comb in combs:
        s = 0
        lens = []
        for c in comb:
            lens.append(weak[c]-weak[s])
            s = c+1
        lens.append(weak[-1]-weak[s])
        lens.sort(reverse=True)
        result = True
        for i in range(len(lens)):
            if dist[i] < lens[i]:
                result = False
                break
        if result: return True
    return False
        



def solution(n, weak, dist):
    answer = -1
    dist.reverse()
    for j in range(len(dist)):
        for i in range(len(weak)):
            arr = weak[i:] + list(map(lambda x: x+n, weak[:i]))

            if j==0:
                if arr[-1] - arr[0] <= dist[0]: return 1
            else: 
                if divide(arr, dist[:j+1]):
                    return j+1

    return answer


print(solution(12, [1, 3, 4, 9, 10]	, [1, 2, 3, 4]))