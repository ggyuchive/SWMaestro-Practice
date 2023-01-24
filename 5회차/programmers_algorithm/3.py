def solution(number, k):
    answer = ''
    n = len(number)
    size = n-k
    pnt = 0
    dp = [[0 for i in range(10)] for j in range(n+1)]
    for i in range(1, n+1):
        for j in range(0, 10):
            dp[i][j]=dp[i-1][j]
        dp[i][int(number[i-1])]+=1
        
    pnt = 0
    while pnt < n and len(answer)<size:
        l = pnt
        r = n-(size-len(answer)-1)
        for i in range(9, -1, -1):
            if dp[r][i]-dp[l][i]>0:
                answer=answer+str(i)
                break
        while number[pnt]!=str(i):
            pnt+=1
        pnt+=1
    return answer