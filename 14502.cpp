//
//  14502.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
typedef pair<int, int> P;

queue<P> q;
int graph[9][9];
int bfs_graph[9][9];
bool visited[9][9];
bool bfs_visited[9][9];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}};
int row,col;
int ans = 0;

void bfs(){
    while(!q.empty()){
        auto a = q.front();
        int r = a.first;
        int c = a.second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            if(rr<0 || rr>=row || cc<0 || cc>=col)
                continue;
            
            if(!bfs_visited[rr][cc] && bfs_graph[rr][cc] == 0){
                bfs_visited[rr][cc] = true;
                bfs_graph[rr][cc] = 2;
                q.push(P(rr,cc));
            }
        }
    }
}

void dfs(int r, int c, int depth){
    if(depth > 3)
        return;
    if(depth == 3){
        memset(bfs_visited, false, sizeof(bfs_visited));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                bfs_graph[i][j] = graph[i][j];
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j] && graph[i][j] == 2){
                    q.push(P(i,j));
                    bfs();
                }
            }
        }
        
        int temp = 0;
        for(int i=0; i<row; i++){ //search space
            for(int j=0; j<col; j++){
                if(bfs_graph[i][j] == 0){
                    temp += 1;
                }
            }
        }
        
        if(ans < temp ){
            ans = temp;
        }
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(!visited[i][j] && graph[i][j] == 0){
                visited[i][j] = true;
                graph[i][j] = 1;
                dfs(i,j,depth+1);
                graph[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
    
}

int main(){
    cin >> row >> col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> graph[i][j];
        }
    }
    
//    for(int i=0; i<row; i++){
//        for(int j=0; j<col; j++){
//            if(!visited[i][j] && graph[i][j] == 0){
//                visited[i][j] = true;
//                graph[i][j] = 1;
//                dfs(i,j,1);
//                graph[i][j] = 0;
//                visited[i][j] = false;
//            }
//        }
//    }
    dfs(0,0,0);
    
    cout << ans << "\n";
    
    return 0;
}
