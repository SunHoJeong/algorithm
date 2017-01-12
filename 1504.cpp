//
//  1504.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 100000
typedef pair<int, int> P;

int n;
int e;
bool visited[801] = {false,};
vector<P> v[801];
queue<int> q;
int dist[801];

int bfs(int start, int end){
    //printf("s:%d e:%d\n",start, end);
    for(int i=0; i<=n; i++){ //dist from start to end
        dist[i] = INF;
    }
    q.push(start);
    dist[start] = 0;
    
    //dist[n] vs dist[i] + v[i].back().second
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        //printf("pop:%d\n",temp);
        for(int i=0; i<v[temp].size(); i++){ // temp ㅇㅇㅇㅇㅇ-> i
            //printf("v[%d][%d]->%d\n", temp, v[temp][i].first, v[temp][i].second);
            //printf("%d %d %d\n",dist[v[temp][i].first], dist[temp], v[temp][i].second);
            if(temp != end && (dist[v[temp][i].first] > dist[temp] + v[temp][i].second) ) {
                dist[v[temp][i].first] = dist[temp] + v[temp][i].second;
                q.push(v[temp][i].first);
                //printf("dist[%d]:%d\n", v[temp][i].first, dist[temp] + v[temp][i].second);
                //printf("if\n");
            }
        }
        
    }
    
    return dist[end];
}

int main(){
    
    scanf("%d %d", &n, &e);
    for(int i=0; i<e; i++){
        int temp1;
        int temp2;
        int w;
        
        scanf("%d %d %d", &temp1, &temp2, &w);
        //printf("v[%d][%d] : %d\n",temp1, temp2, w);
        //printf("v[%d][%d] : %d\n",temp2, temp1, w);
        v[temp1].push_back(P(temp2, w));
        v[temp2].push_back(P(temp1, w));
        
    }
    //printf("---%d, %d---\n",v[3][1].first, v[3][1].second);

//    for(int i=1; i<=n; i++){
//        for(int j=0; j<v[i].size(); j++){
//            printf("v[%d][%d]: %d\n", i,v[i][j].first, v[i][j].second);
//        }
//    }
    
    int first;
    int second;
    scanf("%d %d", &first, &second);

    int temp = bfs(first, second);
    
    
    int ans = min(bfs(1,first)+temp+bfs(second,n), bfs(1,second)+temp+bfs(first,n) );
    
//    printf("%d %d %d\n",bfs(1,first),temp,bfs(second,n));
//    printf("%d %d %d\n",bfs(1,second), temp, bfs(first,n));

    
    if(ans < INF){
        printf("%d\n", ans);
    }
    else{
        printf("%d\n", -1);
    }
    
    return 0;
}
