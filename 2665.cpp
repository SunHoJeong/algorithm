//
//  2665.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

queue<int> q;
int graph[55][55];
int d[55][55];
bool visited[55][55];
int n;
int ans = 123456789;

/*
void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start/10000;
        int col = start%10000;
        
        if(graph[row-1][col] != -2 && !visited[row-1][col]){
            visited[row-1][col] = true;
            q.push((row-1)*10000+col);
            if(graph[row-1][col] == 1){ //안막힘
                d[row-1][col] = min(d[row-1][col], d[row][col]);
            }
            else if(graph[row-1][col] == 0){ //막힘
                d[row-1][col] = min(d[row-1][col], d[row][col] +1);
            }
        }
        if(graph[row][col+1] != -2 && !visited[row][col+1] ){
            visited[row][col+1] = true;
            q.push(row*10000+col+1);
            if(graph[row][col+1] == 1){
                d[row][col+1] = min(d[row][col+1], d[row][col]);
            }
            else if(graph[row][col+1] == 0){
                d[row][col+1] = min(d[row][col+1], d[row][col] +1);
            }
        }
        if(graph[row+1][col] != -2 && !visited[row+1][col]){
            visited[row+1][col] = true;
            q.push((row+1)*10000+col);

            if(graph[row+1][col] == 1){
                d[row+1][col] = min(d[row+1][col], d[row][col]);
            }
            else if(graph[row+1][col] == 0){
                d[row+1][col] = min(d[row+1][col], d[row][col] +1);
            }
        }
        if(graph[row][col-1] != -2 && !visited[row][col-1]){
            visited[row][col-1] = true;
            q.push(row*10000+col-1);

            if(graph[row][col-1] == 1){
                d[row][col-1] = min(d[row][col-1], d[row][col]);
            }
            else if(graph[row][col-1] == 0){
                d[row][col-1] = min(d[row][col-1], d[row][col] +1);
            }
        }
    }
}*/

void bfs(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        int row = start/10000;
        int col = start%10000;
        
        if(graph[row+1][col] != -2){
            if(graph[row+1][col] == 1){
                d[row+1][col] = min(d[row+1][col], d[row][col]);
            }
            else if(graph[row+1][col] == 0){
                d[row+1][col] = min(d[row+1][col], d[row][col]+1);
            }
            q.push((row+1)*10000+col);
        }
        if(graph[row][col+1] != -2){
            if(graph[row][col+1] == 1){
                d[row][col+1] = min(d[row][col+1], d[row][col]);
            }
            else if(graph[row][col+1] == 0){
                d[row][col+1] = min(d[row][col+1], d[row][col]+1);
            }
            q.push(row*10000+col+1);
        }
        if(graph[row][col-1] != -2){
            if(graph[row][col-1] == 1){
                d[row][col-1] = min(d[row][col-1], d[row][col]);
            }
            else if(graph[row][col-1] == 0){
                d[row][col-1] = min(d[row][col-1], d[row][col]+1);
            }
            q.push(row*10000+col-1);
        }
        
        if(graph[row-1][col] != -2){
            if(graph[row-1][col] == 1){
                d[row-1][col] = min(d[row-1][col], d[row][col]);
            }
            else if(graph[row-1][col] == 0){
                d[row-1][col] = min(d[row-1][col], d[row][col]+1);
            }
            q.push((row-1)*10000+col);
        }
    }
}

int main(){
    cin >> n;
    
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=n+1; j++){
            graph[i][j] = -1;
            d[i][j] = 123456789;
        }
    }
    
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0'){
                graph[i][j+1] = 0;
            }
            else if(str[j] == '1'){
                graph[i][j+1] = 1;
            }
        }
    }
    d[1][1] = 0;
    q.push(10001);
    bfs();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    cout << d[n][n] << "\n";
    
    return 0;
}
