//
//  1389.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[101];
queue<int> q;
int d[101];
int sum[101];
bool visited[101];

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int next : v[x]){
            if(!visited[next]){
                visited[next] = true;
                d[next] = d[x]+1;
                q.push(next);
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        memset(d, 0, sizeof(d));
        
        q.push(i);
        visited[i] = true;
        d[i] = 0;
        bfs();
        
        for(int j=1; j<=n; j++){
            if(i != j){
                sum[i] += d[j];
            }
        }
    }
    
    int min = 1000000000;
    int index = 0;
    for(int i=1; i<=n; i++){
        if(min > sum[i]){
            min = sum[i];
            index = i;
        }
    }
    printf("%d\n",index);
    
    return 0;
}
