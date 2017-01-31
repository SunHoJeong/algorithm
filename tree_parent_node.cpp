//
//  tree_parent_node.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;

vector<int> v[MAX];
queue<int> q;
int parent[MAX];
bool visited[MAX];
int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n-1; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    
    q.push(1);
    visited[1] = true;
    
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
        cout << parent[i] << "\n";
    }
    return 0;
}

