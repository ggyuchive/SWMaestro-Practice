def solution(word):
    arr=['A', 'E', 'I', 'O', 'U']
    v = []
    for i in range(1,6):
        comb=1
        for j in range(i):
            comb*=5
        for j in range(comb):
            cmb=j
            s = ''
            for k in range(i):
                s+=(arr[cmb%5])
                cmb=int(cmb/5)
            v.append(s)
    v.sort()
    for i in range(len(v)):
        if word==v[i]:
            return i+1