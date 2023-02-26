#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    int n = users.size();
    int m = emoticons.size();
    int comb = 1;
    for (int i = 0; i < m; i++) comb*=4;
    vector<int> v;
    v.resize(m, 0);
    
    int maxuser = 0; int maxprofit = 0;
    for (int i = 0; i < comb; i++) {
        int cmb = i;
        for (int j = 0; j < m; j++) {
            int t = cmb%4;
            cmb/=4;
            t = (t+1)*10;
            v[j] = t;
        }
        int user = 0; int profit = 0;
        for (int j = 0; j < n; j++) {
            int buy = 0; int isenter = 0;
            for (int k = 0; k < m; k++) {
                if (v[k] >= users[j][0]) {
                    buy = buy + emoticons[k]*(100-v[k])/100;
                }
            }
            if (buy >= users[j][1]) {
                isenter++; buy = 0;
            }
            user += isenter; profit += buy;
        }
        if (user > maxuser || (user==maxuser && profit > maxprofit)) {
            maxuser = user;
            maxprofit = profit;
        }
    }
    answer.push_back(maxuser);
    answer.push_back(maxprofit);
    return answer;
}