# https://programmers.co.kr/learn/courses/30/lessons/42883?language=python3

'''
처음에는 각 숫자의 위치를 저장해서 (ex, '213' => [[],[1],[0],[2]...])
제일 큰 숫자보다 오른쪽에 있는 숫자의 갯수가 남겨야하는 갯수보다 많으면 그걸 포함하고
그 왼쪽에서 다음 큰 수를 찾고... 이런식으로 했다가 다 꼬여버림.

해결한 풀이는
숫자 배열중에 제일 큰 숫자를 모두 뽑고
그 다음 큰 숫자를 모두 뽑고
단 뒤에서 부터 뽑음.
'''

def makeBigNumber(strNum, k, nowNumber):
    if k <= 0 or nowNumber <= -1:
        return ''

    if len(strNum) <= k:
        return strNum
    
    locs = [i for i in range(len(strNum)-1, -1, -1) if ord(strNum[i])-ord('0') == nowNumber]
    
    if k <= len(locs):
        return str(nowNumber)*k
    
    k -= len(locs)
    answer = ''
    end = len(strNum)

    for loc in locs:
        tempAnswer = makeBigNumber(strNum[loc+1:end], k, nowNumber-1)
        answer = str(nowNumber) + tempAnswer + answer
        end = loc
        k -= len(tempAnswer)

    answer = makeBigNumber(strNum[0:end], k, nowNumber-1) + answer
    
    return answer

def solution(number, k):
    answer = makeBigNumber(number, len(number) - k, 9)
    return answer

# print(solution("4177252841", 4))