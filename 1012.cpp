//
//  1012.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>

using namespace std;

int graph[55][55];
int visited[55][55];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1} };
int row, col, b;

void dfs(int x){
    int r = x/10000;
    int c = x%10000;
    
    visited[r][c] = true;
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr < 0 || rr >= row || cc < 0 || cc >= col)
            continue;
        
        if(!visited[rr][cc] && graph[rr][cc] == 1){
            dfs(rr*10000+cc);
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));
        
        scanf("%d %d %d", &col, &row, &b);
        
        for(int k=1; k<=b; k++){
            int t1,t2;
            scanf("%d %d", &t1, &t2);
            graph[t2][t1] = 1;
        }
        
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j] && graph[i][j] ==1){
                    ans += 1;
                    dfs(i*10000+j);
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
