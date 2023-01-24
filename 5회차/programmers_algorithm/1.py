def solution(n, lost, reserve):
    answer = n
    nothave = [0 for i in range(n)]
    morehave = [0 for i in range(n)]
    for i in range(0,len(lost)):
        nothave[lost[i]-1]=1
    for i in range(0,len(reserve)):
        morehave[reserve[i]-1]=1
    for i in range(0, n):
        if nothave[i]==1 and morehave[i]==1:
            nothave[i],morehave[i]=0,0
        if nothave[i]==1:
            answer-=1
        
    for i in range(0, n):
        if nothave[i]==1:
            if i-1>=0 and morehave[i-1]==1:
                answer+=1
                morehave[i-1],nothave[i]=0,0
            elif i+1<n and morehave[i+1]==1:
                answer+=1
                morehave[i+1],nothave[i]=0,0
    return answer