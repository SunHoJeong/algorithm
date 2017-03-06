//
//  3109.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

char graph[10001][501];
bool visited[10001][501];
int dir[3][2] = {{-1,1}, {0,1}, {1,1}};
int row,col;
int ans = 0;
bool check = false;

void dfs(int r, int c){
    if(check){
        return;
    }
    
    visited[r][c] = true;
    
    if(c == col-1){
        check = true;
        ans++;
        return;
    }
    
    for(int i=0; i<3; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr < 0 || rr >= row || cc < 0 || cc >= col)
            continue;
        
        if(!visited[rr][cc] && graph[rr][cc] != 'x'){
            dfs(rr,cc);
        }
    }
    
}

int main(){
    cin >> row >> col;
    for(int i=0; i<row; i++){
        cin >> graph[i];
    }
    
    for(int i=0; i<row; i++){
        if(!visited[i][0]){
            check = false;
            dfs(i, 0);
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
