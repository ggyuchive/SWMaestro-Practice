def solution(people, limit):
    answer = 0
    n = len(people)
    people.sort()
    l, r = 0, n-1
    while l<=r:
        sum = people[r]
        r-=1
        while l<=r and sum+people[l]<=limit:
            sum += people[l]
            l+=1
        answer+=1
    return answer