//
//  2146.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int graph[102][102]={0,};
int island[102][102] = {0,};
bool visited[102][102] = {false,};
int cnt = 0;
queue<int> q;
int bridge = 123456789;

void cal_dis(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start/10000;
        int col = start%10000;
        
        if(graph[row-1][col] == -1 && !visited[row-1][col]){
            graph[row-1][col] = graph[row][col]+1;
            island[row-1][col] = island[row][col];
            q.push((row-1)*10000+col);
        }
        
        if(graph[row][col+1] == -1 && !visited[row][col+1]){
            graph[row][col+1] = graph[row][col]+1;
            island[row][col+1] = island[row][col];
            q.push(row*10000+col+1);
        }

        if(graph[row+1][col] == -1 && !visited[row+1][col]){
            graph[row+1][col] = graph[row][col]+1;
            island[row+1][col] = island[row][col];
            q.push((row+1)*10000+col);
        }

        if(graph[row][col-1] == -1 && !visited[row][col-1]){
            graph[row][col-1] = graph[row][col]+1;
            island[row][col-1] = island[row][col];
            q.push(row*10000+col-1);
        }

    }
}

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start/10000;
        int col = start%10000;
        
        if(graph[row-1][col] == 0 && !visited[row-1][col]){
            island[row-1][col] = cnt;
            visited[row-1][col] = true;
            q.push((row-1)*10000+col);
        }
        if(graph[row][col+1] == 0 && !visited[row][col+1]){
            island[row][col+1] = cnt;
            visited[row][col+1] = true;
            q.push((row)*10000+col+1);
        }
        if(graph[row+1][col] == 0 && !visited[row+1][col]){
            island[row+1][col] = cnt;
            visited[row+1][col] = true;
            q.push((row+1)*10000+col);
        }
        if(graph[row][col-1] == 0 && !visited[row][col-1]){
            island[row][col-1] = cnt;
            visited[row][col-1] = true;
            q.push(row*10000+col-1);
        }
    
    }
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=n+1; j++){
            graph[i][j] = -2;
        }
    }
    
    for(int i=1; i<=n; i++){ //-1 바다, 0 육지
        for(int j=1; j<=n; j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 0){
                graph[i][j] = -1;
            }
            else if(temp == 1){
                graph[i][j] = 0;
            }
        }
    }
    /*
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=n+1; j++){
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }*/
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] == 0 && !visited[i][j]){
                cnt++;
                island[i][j] = cnt;
                visited[i][j] = true;
                q.push(i*10000+j);
                bfs();
                
            }
        }
    }
    /*
    printf("--섬찾기 후--\n");
    printf("--graph--\n");
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=n+1; j++){
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
    
    printf("--island--\n");
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=n+1; j++){
            printf("%3d ", island[i][j]);
        }
        printf("\n");
    }*/
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] == 0){
                q.push(i*10000+j);
            }
        }
    }
    cal_dis();
    
//    printf("--거리찾기 후--\n");
//    printf("--graph--\n");
//    for(int i=0; i<=n+1; i++){
//        for(int j=0; j<=n+1; j++){
//            printf("%3d ", graph[i][j]);
//        }
//        printf("\n");
//    }
//    
//    printf("--island--\n");
//    for(int i=0; i<=n+1; i++){
//        for(int j=0; j<=n+1; j++){
//            printf("%3d ", island[i][j]);
//        }
//        printf("\n");
//    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(island[i][j] != 0){
                if(island[i][j] != island[i-1][j] && island[i-1][j] != 0 ){
                    //printf("(%d %d) (%d %d) %d\n",i,j, i-1,j, graph[i][j]+graph[i-1][j]);
                    if(bridge > graph[i][j]+graph[i-1][j]){
                        bridge = graph[i][j] + graph[i-1][j];
                    }
                }
                if(island[i][j] != island[i][j+1] && island[i][j+1] != 0 ){
                    //printf("(%d %d) (%d %d) %d\n",i,j, i,j+1, graph[i][j]+graph[i][j+1]);
                    if(bridge > graph[i][j]+graph[i][j+1]){
                        bridge = graph[i][j] + graph[i][j+1];
                    }
                }
                if(island[i][j] != island[i+1][j] && island[i+1][j] != 0 ){
                    //printf("(%d %d) (%d %d) %d\n",i,j, i+1,j, graph[i][j]+graph[i+1][j]);
                    if(bridge > graph[i][j]+graph[i+1][j]){
                        bridge = graph[i][j] + graph[i+1][j];
                    }
                }
                if(island[i][j] != island[i][j-1] && island[i][j-1] != 0){
                    //printf("(%d %d) (%d %d) %d\n",i,j, i,j-1, graph[i][j]+graph[i][j-1]);
                    if(bridge > graph[i][j]+graph[i][j-1]){
                        bridge = graph[i][j] + graph[i][j-1];
                    }
                }
            }
        }
    }
    if(cnt <= 1){
        printf("%d\n",0);
    }
    else{
        printf("%d\n",bridge);
    }
    
    
    
    
}
