//
//  2638.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> P;

queue<P> q;
queue<P> cheeze;
int graph[102][102];
bool visited[102][102];
int dir[4][2] ={ {-1,0},{0,1},{1,0},{0,-1}};

int main(){
    int row, col;
    cin >> row >> col;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }
    graph[1][1] = -1;
    visited[1][1] = true;
    q.push(P(1,1));
    
    while(!q.empty()){ //외부공기 만들기
        auto x = q.front();
        q.pop();
        int r = x.first;
        int c = x.second;
        
        for(int i=0; i<4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            
            if(rr <= 0 || rr > row ||cc <= 0 || cc > col)
                continue;
            
            if(!visited[rr][cc] && graph[rr][cc] == 0){
                visited[rr][cc] = true;
                graph[rr][cc] = -1;
                q.push(P(rr,cc));
            }
        }
        
    }

    int ans = 0;
    while(1){
        
        int cnt = 0;
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                visited[i][j] = 0;
                if(graph[i][j] == -1)
                    cnt += 1;
            }
        }
        if(cnt == row*col)
            break;
        
        ans += 1;
        for(int i=1; i<=row; i++){//치즈 bfs
            for(int j=1; j<=col; j++){
                if(!visited[i][j] && graph[i][j] == 1){
                    visited[i][j] = true;
                    q.push(P(i,j));
                    while(!q.empty()){
                        auto x = q.front();
                        q.pop();
                        int r = x.first;
                        int c = x.second;
                        
                        int airCnt = 0;
                        for(int i=0; i<4; i++){
                            int rr = r + dir[i][0];
                            int cc = c + dir[i][1];
                            
                            if(rr <= 0 || rr > row ||cc <= 0 || cc > col)
                                continue;
                            
                            if(graph[rr][cc] == -1){
                                airCnt += 1;
                            }
                            else if(!visited[rr][cc] && graph[rr][cc] == 1){
                                visited[rr][cc] = true;
                                q.push(P(rr,cc));
                            }
                        }
                        
                        if(airCnt >= 2){ //공기가 2 이상이면 녹음
                            cheeze.push(P(r,c));
                        }
                        
                        
                    }//while
                }//if
            }//for:j
        }//for:i
        
        while(!cheeze.empty()){
            auto c = cheeze.front();
            int c_r = c.first;
            int c_c = c.second;
            cheeze.pop();
            graph[c_r][c_c] = -1;
            
            for(int i=0; i<4; i++){
                int c_rr = c_r + dir[i][0];
                int c_cc = c_c + dir[i][1];
                if(c_rr <=0 || c_rr > row || c_cc <=0 || c_cc >col)
                    continue;
                
                if(!visited[c_rr][c_cc] && graph[c_rr][c_cc] == 0){
                    visited[c_rr][c_cc] = true;
                    cheeze.push(P(c_rr,c_cc));
                }
            }
        }
        
    }
    
    cout << ans << "\n";
    return 0;
}//main
