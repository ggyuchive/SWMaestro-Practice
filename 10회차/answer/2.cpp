#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool judge_true (vector<vector<int>> gidung, vector<vector<int>> bobobo, int n) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n+1; x++) {
            if (gidung[y][x] == 1) {
                int tag = 0;
                if (y == 0) tag = 1;
                if ((x>0 && bobobo[y][x-1] == 1)|| bobobo[y][x] == 1) tag = 1;
                if (y>0 && gidung[y-1][x] == 1) tag = 1;
                if (tag == 0) return false;
            }
        }
    }
    for (int y = 1; y < n+1; y++) {
        for (int x = 0; x < n; x++) {
            if (bobobo[y][x] == 1) {
                int tag = 0;
                if (gidung[y-1][x] == 1 || (x+1<n+1 && gidung[y-1][x+1] == 1)) tag = 1;
                if ((x-1>=0 && bobobo[y][x-1]==1) && (x+1<n && bobobo[y][x+1]==1)) tag = 1;
                if (tag == 0) return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int q = build_frame.size();
    vector<vector<int>> gidung, bobobo;
    gidung.resize(n, vector<int>(n+1,0));
    bobobo.resize(n+1, vector<int>(n,0));
    
    for (int i = 0; i < q; i++) {
        int x, y, a, b;
        x = build_frame[i][0]; y = build_frame[i][1];
        a = build_frame[i][2]; b = build_frame[i][3];
        if (a == 0 && b == 1) { // 기둥 설치
            gidung[y][x] = 1;
            if (judge_true(gidung, bobobo, n) == false) {
                gidung[y][x] = 0;
            }
        }
        if (a == 1 && b == 1) { // 보 설치
            bobobo[y][x] = 1;
            if (judge_true(gidung, bobobo, n) == false) {
                bobobo[y][x] = 0;
            } 
        }
        if (a == 0 && b == 0) { // 기둥 삭제
            gidung[y][x] = 0;
            if (judge_true(gidung, bobobo, n) == false) {
                gidung[y][x] = 1;
            }
        }
        if (a == 1 && b == 0) { // 보 삭제
            bobobo[y][x] = 0;
            if (judge_true(gidung, bobobo, n) == false) {
                bobobo[y][x] = 1;
            } 
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1; j++) {
            if (gidung[i][j] == 1)
            answer.push_back({j,i,0});
        }
    }
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n; j++) {
            if (bobobo[i][j] == 1)
            answer.push_back({j,i,1});
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}