//
//  1967.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

const int MAX = 10001;
vector<P> v[MAX];
queue<int> q;
bool visited[MAX];
int dist[MAX];

void bfs(int start){
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            if(!visited[v[node][i].first]){
                dist[v[node][i].first] = dist[node] + v[node][i].second;
                //printf("(%d,%d)%d  = %d + %d\n",node,i,dist[v[node][i].first], dist[node], v[node][i].second);
                visited[v[node][i].first] = true;
                q.push(v[node][i].first);
            }
        }
        
    }
}

int main(){ //node_num = 1
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        int st, des, w;
        scanf("%d %d %d", &st, &des, &w);
        v[st].push_back(P(des, w));
        v[des].push_back(P(st, w));
    }
    
//    for(int i=1; i<=n; i++){
//        for(int j=0; j<v[i].size(); j++){
//            printf("%d %d: %d\n", i, v[i][j].first, v[i][j].second);
//        }
//    }
    
    bfs(1);
    int max = dist[1];
    int index = 0;
    for(int i=1; i<=n; i++){
        if(max < dist[i]){
            max = dist[i];
            index = i;
        }
        //printf("%d ",dist[i]);
    }
    //printf("\n");
    
    bfs(index);
    int ans = dist[index];
    
    for(int i=1; i<=n; i++){
        if(ans < dist[i]){
            ans = dist[i];
        }
    }
    
    printf("%d\n", ans);
}
