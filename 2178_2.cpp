//
//  2178_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;
typedef pair<int,int> P;

int graph[105][105];
bool visited[105][105];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1} };
queue<P> q;

int main(){
    int row, col;
    cin >> row >>col;
    
    for(int i=1; i<=row; i++){
        string input;
        cin >> input;
        for(int j=0; j<col; j++){
            if(input[j] == '0'){
                graph[i][j+1] = -1;
            }
            else{
                graph[i][j+1] = 0;
            }
        }
    }
    
    q.push(P(1,1));
    graph[1][1] = 1;
    visited[1][1] = true;
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(r == row && c == col){
            cout << graph[r][c] << "\n";
        }
        
        for(int i=0; i<4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            
            if(rr <= 0 || rr > row || cc <= 0 || cc > col)
                continue;
            if(!visited[rr][cc] && graph[rr][cc] == 0){
                visited[rr][cc] = true;
                graph[rr][cc] = graph[r][c] +1;
                q.push(P(rr,cc));
            }
        }
    }
    
    
    return 0;
}
