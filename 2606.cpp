//
//  2606.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int graph[102][102];
bool visited[102];

queue<int> q;

int main(){
    int n,e;
    cin >> n >> e;
    
    for(int i=0; i<e; i++){
        int st, des;
        cin >> st >> des;
        graph[st][des] = 1;
        graph[des][st] = 1;
    }
    
    visited[1] = true;
    q.push(1);
    
    int ans = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && graph[x][i] == 1){
                visited[i] = true;
                ans += 1;
                q.push(i);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
