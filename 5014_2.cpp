//
//  5014_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1000000;

queue<int> q;
bool visited[1000001];
int dist[1000001];

int main(){
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d ;
    
    visited[s] = true;
    q.push(s);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x == g){
            cout << dist[x] << "\n";
            break;
        }
        
        if(1 <= x-d && !visited[x-d]){
            visited[x-d] = true;
            dist[x-d] = dist[x]+1;
            q.push(x-d);
        }
        if(x+u <= f && !visited[x+u]){
            visited[x+u] = true;
            dist[x+u] = dist[x]+1;
            q.push(x+u);
        }
        
        if(q.empty()){
            cout << "use the stairs" << "\n";
            return 0;
        }
    }
    
    return 0;
}
