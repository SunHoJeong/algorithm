//
//  1167.cpp
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

const int MAX = 100001;
typedef pair<int, int> P;
vector<P> v[MAX];
bool visited[MAX];
int dist[MAX];
int max = 0;
queue<int> q;

void bfs(int start){
    memset(dist, 0, sizeof(dist));
    memset(visited, false, sizeof(visited));
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            if(!visited[v[node][i].first]){
                //printf("--%d %d:  %d--\n", node, v[node][i].first, v[node][i].second);
                dist[v[node][i].first] = dist[node] + v[node][i].second;
                visited[v[node][i].first] = true;
                q.push(v[node][i].first);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        int st;
        scanf("%d", &st);
        while(true){
            int des;
            int w;
            scanf("%d", &des);
            if(des == -1){
                break;
            }
            else{
                scanf("%d", &w);
            }
            //printf("push:%d %d\n",st,des);
            v[st].push_back(P(des,w));
        }
    }
    
//    for(int i=1; i<=n; i++){
//        for(int j=0; j<v[i].size(); j++){
//            printf("%d %d :%d\n", i, v[i][j].first, v[i][j].second);
//        }
//    }
    
    bfs(1);
    int max = dist[1];
    int index = 0;
    for(int i=1; i<=n; i++){
        //printf("%d ", dist[i]);
        if(max < dist[i]){
            max = dist[i];
            index = i;
        }
    }
    //printf("\n");
    
    bfs(index);
    int ans = dist[1];
    int ans_index = 0;
    for(int i=1; i<=n; i++){
        //printf("%d ", dist[i]);
        if(ans < dist[i]){
            ans = dist[i];
            ans_index = i;
        }
    }
    ///printf("\n");
    //printf("지름: %d %d\n", index, ans_index);
    printf("%d\n", ans);
    
    return 0;
    
}
