//
//  7576.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int graph[1001][1001] = {0,};
bool visited[1001][1001] = {false,};
queue<int> q;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start/10000;
        int col = start%10000;
        
        //안익은토마토 0
        if(graph[row+1][col] == 0 && !visited[row+1][col]){
            visited[row+1][col] = true;
            graph[row+1][col] = graph[row][col]+1;
            q.push((row+1)*10000+col);
        }
        if(graph[row][col+1] == 0 && !visited[row][col+1]){
            visited[row][col+1] = true;
            graph[row][col+1] = graph[row][col]+1;
            q.push((row)*10000+col+1);
        }
        if(graph[row-1][col] == 0 && !visited[row-1][col]){
            visited[row-1][col] = true;
            graph[row-1][col] = graph[row][col]+1;
            q.push((row-1)*10000+col);
        }
        if(graph[row][col-1] == 0 && !visited[row][col-1]){
            visited[row][col-1] = true;
            graph[row][col-1] = graph[row][col]+1;
            q.push((row)*10000+col-1);
        }
    }
}

int main(){
    int m, n; //col, row
    scanf("%d %d", &m, &n);
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            graph[i][j] = -1;
        }
    }
    
    for(int i=1; i<=n; i++){ //1 -> 익은토마토, 0 -> 익지않은토마토, -1 -> 토마토 x
        for(int j=1; j<=m; j++){
            int temp;
            scanf("%d", &temp);
            graph[i][j] = temp;
        }
    }
    
    bool flag =  true;
    
    for(int i=1; i<=n; i++){ //익은 토마토
        for(int j=1; j<=m; j++){
            if(graph[i][j] == 1 && !visited[i][j] ){
                visited[i][j] = true;
                q.push(i*10000 + j);
            }
            else if(graph[i][j] ==0){
                flag = false; //안익은토마토가 있다
            }
        }
    }
    
    if(flag){ //저장때부터 모든 토마토가 익어있는 상태
        printf("%d\n",0);
        return 0;
    }
    
    bfs();
    int min =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(graph[i][j] == 0){
                printf("%d\n",-1);
                return 0;
            }
            else if(graph[i][j] >= 1){
                if(graph[i][j] > min){
                    min = graph[i][j];
                }
            }
            //printf("%3d ", graph[i][j]);
        }
        //printf("\n");
    }
    
    printf("%d\n", min-1);
    //저장될때부터 토마토가 다 익어있는 상황 -> 안익은토마토가없다
    //토마토가 모두 익지 못하는 상황 -> bfs 끝난후에 안익은 토마토가 있다.
    
    
    return 0;

}
