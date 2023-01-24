from functools import cmp_to_key

def comp(a, b):
    if a[1]>b[1] or (a[1]==b[1] and a[0]>b[0]):
        return 1
    elif a[1]==b[1] and a[0]==b[0]:
        return 0
    else:
        return -1

def solution(routes):
    answer = 1
    routes = sorted(routes, key=cmp_to_key(comp))
    l, r = routes[0][0], routes[0][1]
    for i in range(1, len(routes)):
        if r < routes[i][0]:
            answer+=1
            l, r = routes[i][0], routes[i][1]
        else:
            l, r = max(l, routes[i][0]), min(r, routes[i][1])
    return answer