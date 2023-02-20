#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

long long solution(int w,int h) {
    long long a = w; long long b = h;
    long long answer = 0;
    long long sum = 0;
    for (ll i = 0; i < min(a,b); i++) {
        answer = answer - (sum/min(a,b));
        sum = sum+max(a,b);
        answer = answer + (sum/min(a,b));
        if (sum%min(a,b)) answer++;
    }
    answer = a*b-answer;
    return answer;
}