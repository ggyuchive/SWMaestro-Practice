import math
def solution(c, y):
    answer = []
    for a in range(1, int(math.sqrt(y))+1):
        if y%a==0:
            b=y/a
            if 2*(a+b)+4==c:
                answer.append(max(a,b)+2)
                answer.append(min(a,b)+2)
                break
    return answer