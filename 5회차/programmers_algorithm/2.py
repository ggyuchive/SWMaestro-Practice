def solution(name):
    answer = 0
    n = len(name)
    for i in range(0, n):
        a = ord(name[i])-ord('A')
        answer += min(a, 26-a)
    
    mini = n-1
    for i in range(0, n):
        if name[i]=='A':
            l, r = i, i
            while r+1<n and name[r+1]=='A':
                r+=1
            ll = max(0,l-1)
            rr = n-1-r
            mini = min(mini, 2*ll+rr)
            mini = min(mini, ll+2*rr)
            
    answer += mini
    return answer