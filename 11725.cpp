//
//  11725.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100001;
int parent[MAX];
bool visited[MAX];
vector<int> v[MAX];
queue<int> q;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    
    visited[1] = true;
    parent[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int a : v[node]){
            if(!visited[a]){
                parent[a] = node;
                visited[a] = true;
                q.push(a);
                
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        printf("%d\n", parent[i]);
    }
    
    return 0;
}
