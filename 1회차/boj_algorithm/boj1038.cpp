#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    if (n >= 1023) cout << -1;
    else {
        int comb = 1<<10;
        vector<ll> arr;
        for (int i = 1; i < comb; i++) {
            int cmb = i;
            vector<ll> v;
            for (int j = 9; j >= 0; j--) {
                if ((cmb>>j)&1) v.push_back(j);
            }
            ll t = 0;
            for (int i = 0; i < v.size(); i++) {
                t = t*10+v[i];
            }
            arr.push_back(t);
        }
        sort(arr.begin(),arr.end());
        cout << arr[n];
    }
}
