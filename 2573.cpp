//
//  2573.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int graph[305][305];
int visited[305][305];
int temp[305][305];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1} };
int row, col;

void dfs(int x){
    int r = x/10000;
    int c = x%10000;
    
    visited[r][c] = true;
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr <= 0 || rr > row || cc <= 0  || cc > col)
            continue;
        
        if(graph[rr][cc] == 0){
            temp[r][c] += 1;
        }
        else if(!visited[rr][cc] && graph[rr][cc] >0){
            dfs(rr*10000+ cc);
        }
    }
    
}

int main(){
    cin >> row >> col;
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }
    
    int island = 0;
    int year = -1;
    bool check = false;
    
    while(true){
        year +=1 ;
        island = 0;
        check = false;
        memset(visited, false, sizeof(visited));
        memset(temp, 0, sizeof(temp));
        
        for(int i=2; i<row; i++){
            for(int j=2; j<col; j++){
                if(!visited[i][j] && graph[i][j] > 0){
                    island += 1;
                    if(island >=2){
                        cout << year << "\n";
                        return 0;
                    }
                    check = true;
                    dfs(i*10000+ j); // (i,j)  dfs start
                }
            }
        }
        
        if(!check){
            cout << 0 << "\n";
            return 0;
        }
//        cout << "--before graph-- \n";
//        for(int i=1; i<=row; i++){
//            for(int j=1; j<=col; j++){
//                cout << graph[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "--temp-- \n";
//        for(int i=1; i<=row; i++){
//            for(int j=1; j<=col; j++){
//                cout << temp[i][j] << " ";
//            }
//            cout << "\n";
//        }
        
        for(int i=2; i<row; i++){
            for(int j=2; j<col; j++){
                graph[i][j] = graph[i][j]-temp[i][j] < 0 ? 0 : graph[i][j]- temp[i][j];
            }
        }
        
//        cout << "--after graph-- \n";
//        for(int i=1; i<=row; i++){
//            for(int j=1; j<=col; j++){
//                cout << graph[i][j] << " ";
//            }
//            cout << "\n";
//        }
    }
    
    
    
    return 0;
}
