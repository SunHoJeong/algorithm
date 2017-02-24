//
//  2468.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int graph[105][105];
bool visited[105][105];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1} };
int d[105];
int n;

void dfs(int x, int k){
    int r = x/10000;
    int c = x%10000;
    
    visited[r][c] = true;
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr <= 0 || rr > n || cc <= 0 || cc > n)
            continue;
        
        if(!visited[rr][cc] && graph[rr][cc] > k){
            dfs(rr*10000+cc, k);
        }
    }
}

int main(){
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int k=1; k<=100; k++){ //높이
        memset(visited, false, sizeof(visited));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!visited[i][j] && graph[i][j] > k){
                    d[k] += 1;
                    dfs(i*10000+j, k);
                }
            }
        }
    }
    
//    for(int i=1; i<=100; i++){
//        cout << d[i] << " ";
//    }
//    cout << "\n";
//
    
    sort(d+1, d+100+1);
//    
//    for(int i=1; i<=100; i++){
//        cout << d[i] << " ";
//    }
//    cout << "\n";
//    
    if(d[100] == 0){
        cout << 1 << "\n";
    }
    else{
        cout << d[100] << "\n";
    }
    
    
    return 0;
}
