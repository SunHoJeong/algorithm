//
//  1260.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int n,m,v;
int graph[1001][1001] = {0,};
bool check[1001] ={false, };
queue<int> q;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        printf("%d ", start);
        
        for(int i=1; i<=n; i++){
            if(graph[start][i] == 1 && check[i] == false){
                q.push(i);
                check[i] = true;
            }
        }
    }
}

void dfs(int x){
    if(check[x] == true){
        return;
    }
    else{
        check[x] = true;
        printf("%d ", x);
    }
    
    for(int i=1; i<=n; i++){
        if(graph[x][i] == 1 && check[i] == false){
            dfs(i);
        }
    }
}

int main(){

    scanf("%d %d %d", &n, &m, &v);
    for(int i=1; i<=m; i++){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        graph[temp1][temp2] = 1; //간선 양방향
        graph[temp2][temp1] = 1;
    }
    
    dfs(v);
    printf("\n");

    for(int i=0; i<=n; i++){
        check[i] = false;
    }
    q.push(v);
    check[v] = true;
    bfs();
    
    printf("\n");
    return 0;
}
