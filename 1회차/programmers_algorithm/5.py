from itertools import permutations
def solution(k, dungeons):
    answer = -1
    n = len(dungeons)
    a=[]
    for i in range(n):
        a.append(i)
    p = list(permutations(a,n))
    for i in range(len(p)):
        cnt=0
        tmpk=k
        for j in range(n):
            if tmpk >= dungeons[p[i][j]][0]:
                tmpk-=dungeons[p[i][j]][1]
                cnt+=1
            else:
                break
        answer=max(answer,cnt)
    return answer