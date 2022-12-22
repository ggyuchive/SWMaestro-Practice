#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n = answers.size();
    int correct[3] = {0,0,0};
    int a[8]={2, 1, 2, 3, 2, 4, 2, 5};
    int b[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for (int i = 0; i < n; i++) {
        if (answers[i]==(i%5)+1) correct[0]++;
        if (answers[i]==a[i%8]) correct[1]++;
        if (answers[i]==b[i%10]) correct[2]++;
    }
    int max = 0;
    for (int i = 0; i < 3; i++) if (max < correct[i]) max=correct[i];
    for (int i = 0; i < 3; i++) if (max == correct[i]) answer.push_back(i+1);
    return answer;
}