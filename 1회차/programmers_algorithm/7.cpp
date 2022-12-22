#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string word) {
    int answer = 0;
    char arr[5] = {'A', 'E', 'I', 'O', 'U'};
    vector<string> v;
    for (int i = 1; i <= 5; i++) {
        int comb = 1;
        for (int j = 0; j < i; j++) comb*=5;
        for (int j = 0; j < comb; j++) {
            int cmb = j; string str;
            for (int k = 0; k < i; k++) {
                str.push_back(arr[cmb%5]);
                cmb/=5;
            }
            v.push_back(str);
        }
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++) {
        if (word==v[i]) return i+1;
    }
}