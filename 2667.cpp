//
//  2667.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int graph[26][26] = {0,};
int arr_danji[26] = {0,};
bool visited[26][26] = {false,};
int danji = 0;
int n; // 5<=n<=25
queue<int> q;

void bfs(){
    int cnt = 0;
    while(!q.empty()){
        int start = q.front();
        q.pop();
        cnt ++;
        
        int row = start / 10000;
        int col = start % 10000;
        
        graph[row][col] = danji;
        
        if(!visited[row][col+1] && graph[row][col+1] != 0){
            visited[row][col+1] = true;
            q.push(row*10000 + col+1);
        }
        if(!visited[row+1][col] && graph[row+1][col] != 0){
            visited[row+1][col] = true;
            q.push(((row+1)*10000) + col);
        }
        if(!visited[row][col-1] && graph[row][col-1] != 0){
            visited[row][col-1] = true;
            q.push(row*10000 + col-1);
        }
        if(!visited[row-1][col] && graph[row-1][col] != 0){
            visited[row-1][col] = true;
            q.push(((row-1)*10000) + col);
        }
    }
    arr_danji[danji-1] = cnt;
}

int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<=n+1; i++){ //init array
        arr_danji[i] = 0;
        for(int j=0; j<=n+1; j++){
            graph[i][j] = 0;
        }
    }
    
    for(int i=1; i<=n; i++){
        char str[26];
        scanf("%s", str);
        for(int j=0; j<strlen(str); j++){
            if(str[j] == '0'){
                graph[i][j+1] = 0;
            }
            else if(str[j] == '1'){
                graph[i][j+1] = 1;
            }
        }
    }
    /*
    printf("--전--\n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }*/
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                
                q.push(i*10000+j);
                danji++;
                bfs();
            }
        }
    }
    sort(arr_danji, arr_danji+danji);
    /*
    printf("--후--\n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }*/
    
    printf("%d\n",danji);
    for(int i=0; i<danji; i++){
        printf("%d\n",arr_danji[i]);
    }
    
}
