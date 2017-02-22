//
//  2583.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 23..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int graph[105][105];
bool visited[105][105];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1} };
int row, col, b;
int cnt = 0;
int d[105];

void dfs(int x){
    int r = x/10000;
    int c = x%10000;
    
    visited[r][c] = true;
    d[cnt] += 1;
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr<0 || rr >= row || cc<0 || cc >= col)
            continue;
        
        if(!visited[rr][cc] && graph[rr][cc]==0){
            dfs(rr*10000+cc);
        }
    }
}

int main(){
    memset(graph, 0, sizeof(graph));

    scanf("%d %d %d", &row, &col, &b);
    
    for(int i=1; i<=b; i++){
        int l_x, l_y, r_x, r_y;
        scanf("%d %d %d %d",&l_x, &l_y, &r_x, &r_y);
        
        for(int i=l_y; i<r_y; i++){
            for(int j=l_x; j<r_x; j++){
                graph[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(!visited[i][j] && graph[i][j] == 0){
                cnt += 1;
                dfs(i*10000+j);
            }
        }
    }
    
    sort(d+1, d+cnt+1);
    printf("%d\n",cnt);
    for(int i=1; i<=cnt; i++){
        printf("%d ",d[i]);
    }
    return 0;
}
