#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    int cnt = 0;
    vector<pair<int,pair<int,int>>> edge;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            int n1 = i*n+j;
            int n2 = i*n+j+1;
            int c = 0;
            if (abs(land[i][j]-land[i][j+1])>height) c=abs(land[i][j]-land[i][j+1]);
            edge.push_back({c,{n1,n2}});
            edge.push_back({c,{n2,n1}});
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n-1; i++) {
            int n1 = i*n+j;
            int n2 = (i+1)*n+j;
            int c = 0;
            if (abs(land[i+1][j]-land[i][j])>height) c=abs(land[i+1][j]-land[i][j]);
            edge.push_back({c,{n1,n2}});
            edge.push_back({c,{n2,n1}});
        }
    }
    sort(edge.begin(),edge.end());
    
    int N = n*m;
    int parent[N];
    int hei[N];
    for (int i = 0; i < N; i++) {
        parent[i]=i; hei[i]=0;
    }
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int c = edge[i].first;
        while (a != parent[a]) a = parent[a];
        while (b != parent[b]) b = parent[b];
        if (a != b) {
            answer += c;
            if (hei[a] > hei[b]) {
                parent[b] = a;
            }
            else if (hei[a] < hei[b]) {
                parent[a] = b;
            }
            else {
                parent[a] = b;
                hei[b]++;
            }
        }
    }
    
    return answer;
}