#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    vector<int> ans;
    ans.resize(n, 0);
    vector<string> v;
    for (int i = 0; i < n; i++) {
        v.push_back(enroll[i]);
    }
    sort(v.begin(),v.end());
    map<string,int> m;
    for (int i = 0; i < n; i++) {
        m[v[i]] = i;
    }
    int parent[n];
    for (int i = 0; i < n; i++) parent[i]=-1;
    for (int i = 0; i < n; i++) {
        int ind = m[enroll[i]];
        if (referral[i] != "-") {
            parent[ind] = m[referral[i]];
        }
    }
    for (int i = 0; i < seller.size(); i++) {
        int x = m[seller[i]];
        int money = amount[i]*100;
        while (true) {
            ans[x]+=(money-money/10);
            money = money-(money-money/10);
            x = parent[x];
            if (x==-1) break;
        }
    }
    vector<int> answer;
    answer.resize(n, 0);
    for (int i = 0; i < n; i++) {
        answer[i] = ans[m[enroll[i]]];
    }
    return answer;
}