//
//  9466.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int graph[100001] = {0,};
bool visited[100001] = {false,};
queue<int> q;

void bfs(){
    int first = q.front();
    int before = -1;
    map<int, int> m;
    
    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        if(graph[start] == first){ //자기순환
            printf("cycle:%d\n",graph[start]);
        }
        else if(graph[start] == m.find(graph[start])->second){
            printf("add map -> %d\n", m.find(graph[start])->second);
        }
        
        if(visited[graph[start]] == false && graph[start] != 0){
            visited[graph[start]] = true;
            before = start;
            q.push(graph[start]);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d", &n); //2<= n <=100,000
        int temp;
        for(int i=1; i<=n; i++){
            scanf("%d", &temp);
            graph[i] = temp;
        }
        
        for(int i=1; i<=n; i++){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
                printf("push%d\n",i);
                bfs();
            }
        }
    }
}
