#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int ans = 200;
    for (int a = 0; a < n-1; a++) {
        vector<vector<int>> edge;
        edge.resize(n, vector<int>());
        for (int i = 0; i < n-1; i++) {
            if (i!=a) {
                edge[wires[i][0]-1].push_back(wires[i][1]-1);
                edge[wires[i][1]-1].push_back(wires[i][0]-1);
            }
        }
        queue<int> q;
        q.push(0); bool visited[n];
        for (int i = 0; i < n; i++) visited[i]=false;
        visited[0]=true;
        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            int s = q.front(); q.pop();
            for (int i = 0; i < edge[s].size(); i++) {
                int e = edge[s][i];
                if (!visited[e]) {q.push(e); visited[e]=1;}
            }
        }
        if (ans > abs((n-cnt)-cnt)) ans=abs((n-cnt)-cnt);
    }
    return ans;
}