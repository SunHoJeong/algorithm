//
//  2178.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int graph[101][101] = {0,};
bool visited[101][101] = {false,};
queue<int> q;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start/10000;
        int col = start%10000;
        
        if(graph[row+1][col] == 0 && !visited[row+1][col]){
            graph[row+1][col] = graph[row][col] +1;
            visited[row+1][col] = true;
            q.push((row+1)*10000 + col);
        }
        if(graph[row][col+1] == 0 && !visited[row][col+1]){
            graph[row][col+1] = graph[row][col] +1;
            visited[row][col+1] = true;
            q.push(row*10000+col+1);
        }
        if(graph[row-1][col] == 0 && !visited[row-1][col]){
            graph[row-1][col] = graph[row][col] +1;
            visited[row-1][col] = true;
            q.push((row-1)*10000+col);
        }
        if(graph[row][col-1] == 0 && !visited[row][col-1]){
            graph[row][col-1] = graph[row][col] +1;
            visited[row][col-1] = true;
            q.push(row*10000 + col-1);
        }
    }
}

int main(){
    int n, m;
    
    scanf("%d %d", &n, &m); // row, col
    
    for(int i=0; i<=n+1; i++){ //init
        for(int j=0; j<=m+1; j++){
            graph[i][j] = -1;
        }
    }
    
    for(int i=1; i<=n; i++){
        char str[101];
        scanf("%s", str);
        for(int j=0; j<m; j++){
            if(str[j] == '1'){
                graph[i][j+1] = 0;
            }
            else if(str[j] == '0'){
                graph[i][j+1] = -1;
            }
        }
    }
    
//    for(int i=0; i<=n+1; i++){
//        for(int j=0; j<=m+1; j++){
//            printf("%3d ",graph[i][j]);
//        }
//        printf("\n");
//    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(graph[i][j] == 0 && !visited[i][j] ){
                visited[i][j] = true;
                q.push(i*10000 + j);
                bfs();
            }
        }
    }
    
    printf("%d\n",graph[n][m]+1);
    
}
