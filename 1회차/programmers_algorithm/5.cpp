#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = dungeons.size();
    int p[n];
    for (int i = 0; i < n; i++) p[i]=i;
    do {
        int cnt = 0;
        int tmpk = k;
        for (int i = 0; i < n; i++) {
            if (tmpk >= dungeons[p[i]][0]) {
                tmpk-=dungeons[p[i]][1];
                cnt++;
            } else break;
        }
        answer=max(answer,cnt);
    } while (next_permutation(p,p+n));
    return answer;
}