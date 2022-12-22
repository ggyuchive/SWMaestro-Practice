#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    int a[n]; int p[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> p[i];
    int ans = 0;
    int w[1<<n];
    for (int i = 0; i < (1<<n); i++) {
        vector<int> v;
        int sumk = 0;
        w[i]=0;
        
        for (int j = 0; j < n; j++) {
            if (((i>>j)&1)) {
                v.push_back(a[j]);
                w[i]+=p[j];
            }
        }
        sort(v.begin(), v.end());
        
        for (int j = 0; j < v.size(); j++) {
            sumk += (v.size()-j)*v[j];
        }
        if (sumk > k) w[i]=0;
    }
    
    for (int i = 0; i < (1<<n); i++) {
        if (ans < w[i]) ans = w[i];
    }
    cout << ans;
}