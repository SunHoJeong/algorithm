//
//  4963.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int graph[51][51] = {0,};
bool visited[51][51] = {false,};
queue<int> q;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start / 10000;
        int col = start % 10000;
        
        if(graph[row+1][col] == 1 && !visited[row+1][col] ){
            visited[row+1][col] = true;
            q.push((row+1)*10000 + col);
        }
        if(graph[row+1][col+1] == 1 && !visited[row+1][col+1] ){
            visited[row+1][col+1] = true;
            q.push((row+1)*10000 + col+1);
        }
        if(graph[row][col+1] == 1 && !visited[row][col+1] ){
            visited[row][col+1] = true;
            q.push((row)*10000 + col+1);
        }
        if(graph[row-1][col+1] == 1 && !visited[row-1][col+1] ){
            visited[row-1][col+1] = true;
            q.push((row-1)*10000 + col+1);
        }
        if(graph[row-1][col] == 1 && !visited[row-1][col] ){
            visited[row-1][col] = true;
            q.push((row-1)*10000 + col);
        }
        if(graph[row-1][col-1] == 1 && !visited[row-1][col-1] ){
            visited[row-1][col-1] = true;
            q.push((row-1)*10000 + col-1);
        }
        if(graph[row][col-1] == 1 && !visited[row][col-1] ){
            visited[row][col-1] = true;
            q.push((row)*10000 + col-1);
        }
        if(graph[row+1][col-1] == 1 && !visited[row+1][col-1] ){
            visited[row+1][col-1] = true;
            q.push((row+1)*10000 + col-1);
        }
    }
}

int main(){
    
    while(true){
        int w,h;
        int cnt = 0;
        scanf("%d %d", &w, &h);
        if(w == 0 && h ==0){
            break;
        }
        
        for(int i=0; i<=h+1; i++){//graph init
            for(int j=0; j<=w+1; j++){
                graph[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                scanf("%d", &graph[i][j]);
            }
        }
        /*
         for(int i=0; i<=h+1; i++){
         for(int j=0; j<=w+1; j++){
         printf("%3d ", graph[i][j]);
         }
         printf("\n");
         }*/
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(graph[i][j] == 1 && !visited[i][j]){
                    cnt += 1;
                    visited[i][j] = true;
                    q.push(i*10000 + j);
                    bfs();
                }
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
    
    
}
