//
//  11724.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int n, m;
int graph[1001][1001] = {0,};
bool visited[1001] = {false,};
int cnt = 0;
queue<int> q;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        for(int i=1; i<=n; i++){
            if(visited[i] == false && graph[start][i] == 1){
                q.push(i);
                visited[i] = true;
                //printf("(%d %d)\n", start,i);
            }
        }
    }
    
    cnt += 1;
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=m; i++){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        graph[temp1][temp2] = 1;
        graph[temp2][temp1] = 1;
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }*/
    
    for(int i=1; i<=n; i++){
        if(visited[i] == true){
            continue;
        }
        else{
            q.push(i);
            //printf("push%d\n",i);
            visited[i] = true;
            bfs();
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
