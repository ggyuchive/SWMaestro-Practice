#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int n = numbers.size();
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(numbers[i]-'0');
    }
    sort(arr.begin(),arr.end());
    set<int> s;
    do {
        int num = 0;
        for (int i = 0; i < n; i++) {
            num=num*10+arr[i];
            int tag=1;
            for (int i = 2; i*i <= num; i++) {
                if (num%i==0) {tag=0; break;}
            }
            if (tag && num>1) s.insert(num);
        }
    } while (next_permutation(arr.begin(),arr.end()));
    return s.size();
}