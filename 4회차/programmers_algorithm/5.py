def solution(money):
    ans = 0
    n = len(money)
    dp = [[0 for j in range(2)] for i in range(n)]
    dp[0][0],dp[0][1]=0,0
    for i in range(1, n):
        dp[i][0],dp[i][1]=0,0
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])
        dp[i][1]=dp[i-1][0]+money[i]
    ans = max(ans, max(dp[n-1][0], dp[n-1][1]))
    
    dp[0][0],dp[0][1]=0,money[0]
    for i in range(1, n):
        dp[i][0],dp[i][1]=0,0
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])
        dp[i][1]=dp[i-1][0]+money[i]
    ans = max(ans, dp[n-1][0])
    return ans