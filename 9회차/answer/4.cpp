#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int best = 6; int worst = 0;
    int cnt = 0;
    int a[47]; int b[47];
    for (int i = 0; i < 47; i++) {a[i]=0; b[i]=0;}
    
    int az = 0; int bz = 0;
    for (int i = 0; i < 6; i++) {
        if (lottos[i]>=1) a[lottos[i]]=1;
        else az++;
        if (win_nums[i]>=1) b[win_nums[i]]=1;
        else bz++;
    }
    
    for (int i = 1; i < 47; i++) {
        if (a[i]==1 && b[i]==1) cnt++;
    }
    worst = min(6, 7-cnt);
    
    for (int i = 1; i < 47; i++) {
        if (a[i]==1 && b[i]==0) {
            if (bz>=1) {
                cnt++; bz--;
            }
        }
        if (a[i]==0 && b[i]==1) {
            if (az>=1) {
                cnt++; az--;
            }
        }
    }
    cnt = cnt + min(az,bz);
    
    best = min(6, 7-cnt);
    answer.push_back(best);
    answer.push_back(worst);
    return answer;
}