from queue import Queue
def solution(n, wires):
    answer = 200
    for a in range(n-1):
        edge = [[] for i in range(n)]
        for i in range(n-1):
            if i!=a:
                edge[wires[i][0]-1].append(wires[i][1]-1);
                edge[wires[i][1]-1].append(wires[i][0]-1);
        q = Queue()
        visited = [0 for i in range(n)]
        visited[0]=1
        q.put(0)
        cnt=0
        while q.qsize():
            cnt+=1
            s = q.get()
            for i in range(len(edge[s])):
                e = edge[s][i]
                if not visited[e]:
                    q.put(e)
                    visited[e]=1
        answer=min(answer,abs(n-cnt-cnt))
    return answer