#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int n = sizes.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (sizes[i][0]>sizes[i][1]) {
                swap(sizes[i][0],sizes[i][1]);
            }
        }
    }
    int m1 = 0; int m2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (sizes[i][0]>m1) m1=sizes[i][0];
            if (sizes[i][1]>m2) m2=sizes[i][1];
        }
    }
    return m1*m2;
}