//
//  2146_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int graph[101][101];
int dist[101][101];
bool visited[101][101];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1}};
queue<P> q;
int n;
int island = 0;

void makeDist(){
    while(!q.empty()){
        auto a = q.front();
        int r = a.first;
        int c = a.second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            if(rr<0 || rr>n || cc<0 || cc>n)
                continue;
            
            if(!visited[rr][cc] && graph[rr][cc] == 0){
                visited[rr][cc] = true;
                graph[rr][cc] = graph[r][c];
                dist[rr][cc] = dist[r][c]+1;
                q.push(P(rr,cc));
            }
        }
    }
}

void bfs(){
    while(!q.empty()){
        auto a = q.front();
        int r = a.first;
        int c = a.second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            if(rr<0 || rr>n || cc<0 || cc>n)
                continue;
            
            if(!visited[rr][cc] && graph[rr][cc] == 1){
                visited[rr][cc] = true;
                graph[rr][cc] = island;
                q.push(P(rr,cc));
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && graph[i][j] == 1){
                visited[i][j] = true;
                q.push(P(i,j));
                island += 1;
                graph[i][j] = island;
                bfs();
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    while(!q.empty()){
        q.pop();
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && graph[i][j] != 0){
                visited[i][j] = true;
                q.push(P(i,j));
            }
        }
    }
    makeDist();
    
    int ans = 100000000;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                int rr = i+dir[k][0];
                int cc = j+dir[k][1];
                
                if(rr<0 || rr>=n || cc<0 || cc>n)
                    continue;
                
                if(graph[i][j] != graph[rr][cc]){
                    if(ans > dist[i][j]+dist[rr][cc]){
                        ans = dist[i][j] + dist[rr][cc];
                    }
                }
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
