def solution(sizes):
    n = len(sizes)
    for i in range(n):
        for j in range(2):
            if sizes[i][0]>sizes[i][1]:
                sizes[i][0],sizes[i][1]=sizes[i][1],sizes[i][0]
    m1=0
    m2=0
    for i in range(n):
        for j in range(2):
            if sizes[i][0]>m1:
                m1=sizes[i][0]
            if sizes[i][1]>m2:
                m2=sizes[i][1]
    return m1*m2