#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    int w[n][9];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> w[i][j];
        }
    }
    int a[9];
    for (int i = 0; i < 9; i++) a[i]=i;
    int ans = 0;
    do {
        int score = 0;
        int cur = 0;
        if (a[3]!=0) continue;
        for (int i = 0; i < n; i++) {
            
            bool have[3] = {0,0,0};
            int out = 0;
            while (out < 3) {
                int cu = a[cur];
                if (w[i][cu]==0) out++;
                if (w[i][cu]==1) {
                    if (have[2]) {score++; have[2]=0;}
                    if (have[1]) {have[1]=0; have[2]=1;}
                    if (have[0]) {have[0]=0; have[1]=1;}
                    have[0]=1;
                }
                if (w[i][cu]==2) {
                    if (have[2]) {score++; have[2]=0;}
                    if (have[1]) {score++; have[1]=0;}
                    if (have[0]) {have[2]=1; have[0]=0;}
                    have[1]=1;
                }
                if (w[i][cu]==3 || w[i][cu]==4) {
                    for (int i = 0; i < 3; i++) if (have[i]) {have[i]=0; score++;}
                    if (w[i][cu]==3) have[2]=1;
                    else score++;
                }
                cur = (cur+1)%9;
            }
        }
        ans=max(ans,score);
    } while (next_permutation(a,a+9));
    cout << ans;
}