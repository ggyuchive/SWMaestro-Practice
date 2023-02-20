#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int a[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            a[i][j] = i*columns+j+1;
        }
    }
    vector<int> answer;
    
    
    for (int i = 0; i < queries.size(); i++) {
        int x1,y1,x2,y2;
        x1=queries[i][0]; y1=queries[i][1]; x2=queries[i][2]; y2=queries[i][3];
        x1--; y1--; x2--; y2--;
        int ans = 2000000;
        int pnt = 0;
        
        int x = x1; int y = y1;
        int rem = a[x][y];
        while (true) {
            //rem = a[x][y];
            x = x+dx[pnt];
            y = y+dy[pnt];
            if (x<x1 || x>x2 || y<y1 || y>y2) {
                if (pnt==3) break;
                x=x-dx[pnt];
                y=y-dy[pnt];
                pnt++;
                x=x+dx[pnt];
                y=y+dy[pnt];
            }
            int trem = a[x][y];
            a[x][y] = rem;
            rem = trem;
            ans = min(ans,rem);
        }
        answer.push_back(ans);
    }
    
    return answer;
}