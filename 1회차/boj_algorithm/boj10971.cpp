#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    int w[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    int a[n];
    for (int i = 0; i < n; i++) a[i]=i;
    int ans = INT_MAX;
    do {
        int total = 0; int tag=1;
        for (int i = 0; i < n; i++) {
            if (w[a[(i-1+n)%n]][a[i]]) total+=w[a[(i-1+n)%n]][a[i]];
            else tag=0;
        }
        if (tag && ans > total) ans=total;
    } while (next_permutation(a,a+n));
    cout << ans;
}