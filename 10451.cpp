//
//  10451.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int n; //순열의 크기
int graph[1001] = {0,};
bool visited[1001] = {false,};
queue<int> q;
int cnt = 0;

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        if(graph[start] != 0 && visited[graph[start]] == false){
            visited[graph[start]] = true;
            q.push(graph[start]);
            
        }
    }
    
}

int main(){
    int t; //테스트 케이스
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            visited[i] = false;
            graph[i] = 0;
        }
        
        for(int i=1; i<=n; i++){
            int temp;
            scanf("%d", &temp);
            graph[i] = temp;
        }
        
        for(int i=1; i<=n; i++){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
                cnt += 1;
                bfs();
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
        
    }
    
    
    return 0;
    
}
