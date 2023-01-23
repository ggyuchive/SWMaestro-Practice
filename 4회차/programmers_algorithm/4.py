MAX = 100000000
def solution(arr):
    n = len(arr)
    maxdp = [[0 for j in range(n)] for i in range(n)]
    mindp = [[0 for j in range(n)] for i in range(n)]
    for j in range(0, n, 2):
        for i in range(0, n, 2):
            if i+j<n:
                if j==0:
                    maxdp[i][i]=int(arr[i])
                    mindp[i][i]=int(arr[i])
                else:
                    maxdp[i][i+j]=-MAX
                    mindp[i][i+j]=MAX
                    for k in range(1, j, 2):
                        if arr[i+k]=="+":
                            maxdp[i][i+j] = max(maxdp[i][i+j], maxdp[i][i+k-1]+maxdp[i+k+1][i+j])
                            mindp[i][i+j] = min(mindp[i][i+j], mindp[i][i+k-1]+mindp[i+k+1][i+j])
                        else:
                            maxdp[i][i+j] = max(maxdp[i][i+j], maxdp[i][i+k-1]-mindp[i+k+1][i+j])
                            mindp[i][i+j] = min(mindp[i][i+j], mindp[i][i+k-1]-maxdp[i+k+1][i+j])
    return maxdp[0][n-1]