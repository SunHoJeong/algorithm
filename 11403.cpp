//
//  11403.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>

using namespace std;

int graph[105][105];
bool visited[105];
int result[105][105];
int n;

void dfs(int x){
    
    for(int i=1; i<=n; i++){
        if(!visited[i] && graph[x][i]==1){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        for(int j=1; j<=n; j++){
            if(visited[j]){
                result[i][j] = 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
