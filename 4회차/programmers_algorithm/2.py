def solution(triangle):
    answer = 0
    for i in range(0, len(triangle)):
        for j in range(0, len(triangle[i])):
            maxi = triangle[i][j]
            num = triangle[i][j]
            if i-1 >= 0:
                if j<len(triangle[i-1]) and triangle[i-1][j]+num > maxi:
                    maxi = triangle[i-1][j]+num
                if j-1>=0 and j-1<len(triangle[i-1]) and triangle[i-1][j-1]+num > maxi:
                    maxi = triangle[i-1][j-1]+num
            triangle[i][j] = maxi
    for i in range(0, len(triangle[len(triangle)-1])):
        if answer < triangle[len(triangle)-1][i]:
            answer = triangle[len(triangle)-1][i]
    return answer