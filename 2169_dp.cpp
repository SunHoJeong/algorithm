//
//  2169_dp.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int row, col;
int graph[1001][1001];
int d[1003][1003];
bool visited[1001][1001];

int dp(int r, int c){
    cout << r << "," << c << "\n";
    if(r==1 && c==1)
        return graph[1][1];
    
    if(d[r][c] > 0){
        return d[r][c];
    }
    
    if(!visited[r][c]){
        visited[r][c] = true;
        d[r][c] = max(max(dp(r, c-1), dp(r, c+1)), dp(r-1, c)) + graph[r][c];
    }
    
    return d[r][c];
}

int main(){
    cin >> row >> col;
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }
    
    cout << dp(row,col) << "\n";
    
    return 0;
}
