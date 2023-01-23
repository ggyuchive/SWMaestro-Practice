def solution(m, n, puddles):
    arr = [[1 for j in range(m)] for i in range(n)]
    for i in range(0, len(puddles)):
        arr[puddles[i][1]-1][puddles[i][0]-1] = 0
        
    mod = 1000000007
    for i in range(0, n):
        for j in range(0, m):
            if arr[i][j]>0:
                a=0
                b=0
                if i-1>=0:
                    a=arr[i-1][j]
                if j-1>=0:
                    b=arr[i][j-1]
                if i==0 and j==0:
                    arr[i][j]=1
                else:
                    arr[i][j] = (a+b)%mod             
    return arr[n-1][m-1]