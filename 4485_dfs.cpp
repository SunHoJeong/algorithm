//
//  4485.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

// 시간초과 케이스

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1} };
int graph[126][126];
int dist[126][126];
int n;

void sol(int r, int c, int val){
    val += graph[r][c];
    
    dist[r][c] = val;
    //cout << r << "," << c << ":" << dist[r][c] << "\n";
    
    if(r == n-1 && c == n-1){
        return;
    }
    
    for(int i=0; i<4; i++){
        int rr = r + dir[i][0];
        int cc = c + dir[i][1];
        if(rr < 0 || rr >= n || cc < 0 || cc >= n)
            continue;
        if(val + graph[rr][cc]< dist[rr][cc]){
            //cout << rr << "," << cc <<":"<< val << "<" << dist[rr][cc] << "\n";
            sol(rr, cc, val);
        }
    }
}

int main(){
    
    int cnt = 0;
    while(true){
        cin >> n;
        if(n==0)
            break;
        cnt += 1;
        
        memset(graph, 0, sizeof(graph));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> graph[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = INF;
            }
        }
        
        sol(0, 0, 0);
        
        
        cout <<"Problem "<<cnt<<": "<< dist[n-1][n-1] << "\n";
    }
}
