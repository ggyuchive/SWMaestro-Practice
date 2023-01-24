import queue

def solution(n, costs):
    answer = 0
    edge = [[] for i in range(n)]
    cost = []
    for i in range(0, len(costs)):
        cost.append([costs[i][2],costs[i][0],costs[i][1]])
    cost.sort()
    for i in range(len(cost)):
        visited = [0 for i in range(n)]
        s, e = cost[i][1], cost[i][2]
        
        q = queue.Queue()
        q.put(s)
        visited[s]=1
        while not q.empty():
            start = q.get()
            for j in range(len(edge[start])):
                end = edge[start][j]
                if visited[end]==0:
                    q.put(end)
                    visited[end]=1
        
        if visited[e]==0:
            answer+=cost[i][0]
            edge[s].append(e)
            edge[e].append(s)
    return answer