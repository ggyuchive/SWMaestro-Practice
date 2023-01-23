def solution(N, number):
    dp = [[] for i in range(8)]
    tmp = N
    for i in range(0, 8):
        dp[i].append(tmp)
        tmp = tmp*10+N
        
    for i in range(0,8):
        for j in range(0,8):
            if i+1+j<8:
                for k in range(0, len(dp[i])):
                    for l in range(0, len(dp[j])):
                        dp[i+j+1].append(dp[i][k]+dp[j][l])
                        dp[i+j+1].append(dp[i][k]-dp[j][l])
                        dp[i+j+1].append(dp[i][k]*dp[j][l])
                        if (dp[j][l]!=0):
                            dp[i+j+1].append(int(dp[i][k]/dp[j][l]))
        
    for i in range(0, 8):
        for j in range(0, len(dp[i])):
            if dp[i][j]==number:
                return i+1
    #print(dp)
    return -1