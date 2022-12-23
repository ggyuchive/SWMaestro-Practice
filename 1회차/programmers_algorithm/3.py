from itertools import permutations
import math
def solution(numbers):
    n = len(numbers)
    arr = []
    for i in range(n):
        arr.append(int(numbers[i]))
    arr.sort()
    
    p = list(permutations(arr,len(arr)))
    s = {}
    for i in range(len(p)):
        num=0
        for j in range(n):
            num=num*10+p[i][j]
            tag=1
            for k in range(2,int(math.sqrt(num))+1):
                if num%k==0:
                    tag=0
                    break
            if tag and num>1:
                s[num]=1

    return len(s)