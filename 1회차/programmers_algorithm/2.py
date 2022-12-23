def solution(answers):
    answer = []
    n = len(answers)
    correct = [0,0,0]
    a = [2, 1, 2, 3, 2, 4, 2, 5]
    b = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    for i in range(n):
        if answers[i]==(i%5)+1:
            correct[0]+=1
        if answers[i]==a[i%8]:
            correct[1]+=1
        if answers[i]==b[i%10]:
            correct[2]+=1
    max=0
    for i in range(3):
        if max<correct[i]:
            max=correct[i]
    for i in range(3):
        if max==correct[i]:
            answer.append(i+1)
    return answer