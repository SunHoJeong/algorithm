//
//  14502.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

/*
 key point : 2차원 배열을 queue(1차원)으로 바꿔줌으로써 중복제거!
 */

#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

queue<P> q;
vector<P> v;
int graph[9][9];
int bfs_graph[9][9];
bool visited[9][9];
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
            
            if(!visited[rr][cc] && bfs_graph[rr][cc] == 0){
                visited[rr][cc] = true;
                bfs_graph[rr][cc] = 2;
                q.push(P(rr,cc));
            }
        }
    }
}

int sol(){
    memset(visited, false, sizeof(visited));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            bfs_graph[i][j] = graph[i][j];
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(!visited[i][j] && bfs_graph[i][j] == 2){
                visited[i][j] = true;
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

    return temp;
}
int main(){
    cin >> row >> col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0)
                v.push_back(P(i,j));
        }
    }
    
    for(int i=0; i<v.size(); i++){ //2차원 배열 -> q라는 1차원으로 바꿔줌으로써 중복제거!
        for(int j=i+1; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                graph[v[i].first][v[i].second] =
                graph[v[j].first][v[j].second] =
                graph[v[k].first][v[k].second] = 1;
                
                ans = max(ans, sol());
                
                graph[v[i].first][v[i].second] =
                graph[v[j].first][v[j].second] =
                graph[v[k].first][v[k].second] = 0;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
