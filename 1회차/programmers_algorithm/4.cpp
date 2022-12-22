#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int c, int y) {
    vector<int> answer; answer.resize(2,0);
    for (int a = 1; a*a <= y; a++) {
        if (y%a==0) {
            int b=y/a;
            if ((a+2)*(b+2)-a*b==c) {
                answer={max(a,b)+2,min(a,b)+2};
                break;
            }
        }
    }
    return answer;
}