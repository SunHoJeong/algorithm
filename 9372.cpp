//
//  9372.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 7. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int visited[1001];
int graph[1001][1001];

int main(){
    int t=0;
    cin >> t;
    
    while(t--){
        int n = 0;
        int m = 0;
        int count = 0;
        memset(visited, false, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        
        cin >> n >> m;
        
        for(int i=0; i<m; i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            
            graph[temp1][temp2] = 1;
            graph[temp2][temp1] = 1;
            
        }
        q.push(1);
        visited[1] = true;
        
        for(int i=0; i<n; i++){
            int node = q.front();
            q.pop();
            
            for(int j=1; j<=n; j++){
                if(graph[node][j] == 1 && !visited[j]){
                    count += 1;
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        cout << count << "\n";
    }
    
    return 0;
}
